#include "initial_book.h"

#include <algorithm>
#include <fstream>
#include <glog/logging.h>

#include "core/field/core_field.h"
#include "core/kumipuyo.h"
#include "core/kumipuyo_seq.h"

using namespace std;

namespace {

class MatchState {
public:
    MatchState();

    bool match(char, PuyoColor);
    bool match(const std::string&, const Kumipuyo& kp1, const Kumipuyo& kp2);

private:
    PuyoColor colors_[4];
    char chars_[NUM_PUYO_COLORS];
};

MatchState::MatchState()
{
    for (int i = 0; i < 4; ++i)
        colors_[i] = PuyoColor::EMPTY;
    for (int i = 0; i < NUM_PUYO_COLORS; ++i)
        chars_[i] = ' ';
}

bool MatchState::match(char a, PuyoColor c)
{
    DCHECK('A' <= a && a <= 'D') << a;
    int idx = a - 'A';

    if (colors_[idx] == c)
        return true;

    if (colors_[idx] == PuyoColor::EMPTY && chars_[c] == ' ') {
        colors_[idx] = c;
        chars_[c] = a;
        return true;
    }

    return false;
}

bool MatchState::match(const std::string& s, const Kumipuyo& kp1, const Kumipuyo& kp2)
{
    DCHECK_EQ(s.size(), 4UL) << s;
    MatchState ms(*this);

    if (!ms.match(s[0], kp1.axis))
        return false;
    if (!ms.match(s[1], kp1.child))
        return false;
    if (!ms.match(s[2], kp2.axis))
        return false;
    if (!ms.match(s[3], kp2.child))
        return false;

    *this = ms;
    return true;
}

Decision makeDecision(const toml::Value& v)
{
    const toml::Array ary = v.as<toml::Array>();
    int x = ary[0].as<int>();
    int r = ary[1].as<int>();
    return Decision(x, r);
}

} // namespace anonymous

InitialBookField::InitialBookField(const vector<string>& field, map<string, Decision>&& decisions) :
    decisions_(move(decisions))
{
    for (int i = 0; i < MAP_WIDTH; ++i)
        heights_[i] = 0;
    for (int x = 0; x < MAP_WIDTH; ++x) {
        for (int y = 0; y < MAP_HEIGHT; ++y) {
            field_[x][y] = '.';
        }
    }

    for (size_t i = 0; i < field.size(); ++i) {
        CHECK_EQ(field[i].size(), 6UL);
        int y = static_cast<int>(field.size() - i);
        for (int x = 1; x <= 6; ++x) {
            char c = field[i][x-1];
            CHECK(c == '.' || ('A' <= c && c <= 'D')) << c;
            field_[x][y] = field[i][x - 1];
            if (c != '.')
                heights_[x] = std::max(static_cast<int>(heights_[x]), y);
        }
    }
}

Decision InitialBookField::nextDecision(const CoreField& cf, const KumipuyoSeq& seq) const
{
    // Check heights first, since this is fast.
    for (int x = 1; x <= 6; ++x) {
        if (cf.height(x) != heights_[x])
            return Decision();
    }

    MatchState ms;
    for (int x = 1; x <= 6; ++x) {
        int h = heights_[x];
        for (int y = 1; y <= h; ++y) {
            if (!ms.match(field_[x][y], cf.color(x, y)))
                return Decision();
        }
    }

    const Kumipuyo& kp1 = seq.get(0);
    const Kumipuyo& kp2 = seq.get(1);

    // Field matched. check next sequence.
    for (const auto& entry : decisions_) {
        if (ms.match(entry.first, kp1, kp2))
            return entry.second;

        if (!kp2.isRep() && ms.match(entry.first, kp1, kp2.reverse()))
            return entry.second;

        if (!kp1.isRep() && ms.match(entry.first, kp1.reverse(), kp2))
            return entry.second.reverse();

        if (!kp1.isRep() && !kp2.isRep() && ms.match(entry.first, kp1.reverse(), kp2.reverse()))
            return entry.second.reverse();
    }

    return Decision();
}

InitialBook::InitialBook()
{
}

InitialBook::InitialBook(const std::string& filename)
{
    CHECK(load(filename));
}

bool InitialBook::load(const std::string& filename)
{
    ifstream ifs(filename);
    toml::Parser parser(ifs);
    toml::Value v = parser.parse();
    if (!v.valid()) {
        LOG(ERROR) << parser.errorReason();
        return false;
    }

    return loadFromValue(std::move(v));
}

bool InitialBook::loadFromString(const std::string& str)
{
    istringstream iss(str);
    toml::Parser parser(iss);
    toml::Value v = parser.parse();
    if (!v.valid()) {
        LOG(ERROR) << parser.errorReason();
        return false;
    }

    return loadFromValue(std::move(v));
}

bool InitialBook::loadFromValue(const toml::Value& book)
{
    if (!book.valid())
        return false;

    const toml::Array& vs = book.find("book")->as<toml::Array>();
    fields_.reserve(vs.size());
    for (const toml::Value& v : vs) {
        vector<string> f;
        for (const auto& s : v.get<toml::Array>("field"))
            f.push_back(s.as<string>());
        map<string, Decision> m;
        for (const auto& e : v.as<toml::Table>()) {
            if (e.first == "field")
                continue;
            m[e.first] = makeDecision(e.second);
        }

        fields_.emplace_back(f, std::move(m));
    }

    return true;
}

Decision InitialBook::nextDecision(const CoreField& cf, const KumipuyoSeq& seq)
{
    for (const auto& f : fields_) {
        Decision decision = f.nextDecision(cf, seq);
        if (decision.isValid())
            return decision;
    }

    return Decision();
}
