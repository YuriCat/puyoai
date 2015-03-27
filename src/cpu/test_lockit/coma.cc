#include "coma.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <sstream>
#include <string>

#include "core/field_constant.h"

int chainhyk[22][22][221][EE_SIZE], poihyo[22][22][221][EE_SIZE];
int score_hukasa[22][22][221] {};

// NOTE: There should be alternative and useful methods for these methods
// in this anonymous namespace
namespace {
void copyField(int src_field[][TATE], int dst_field[][TAT_SIZE]) {
    for (int i = 0; i < FieldConstant::WIDTH; i++)
        for (int j = 0; j < FieldConstant::HEIGHT + 1; j++)
            dst_field[i][j] = src_field[i][j];
}

template <size_t VSize, typename F>
int countCell(const int field[][VSize], F f) {
    int count = 0;
    for (int i = 0; i < FieldConstant::WIDTH; ++i)
        for (int j = 0; j < FieldConstant::HEIGHT + 1; j++)
            if (f(field[i][j]))
                ++count;
  return count;
}

template <size_t VSize>
int countColoredPuyos(const int field[][VSize]) {
  return countCell(field, [](int cell) {
      return cell != TEST_PUYO_COLOR_EMPTY && cell != TEST_PUYO_COLOR_OJAMA;
    });
}

template <size_t VSize>
int countOjamaPuyos(const int field[][VSize]) {
  return countCell(field, [](int cell) {
      return cell == TEST_PUYO_COLOR_OJAMA;
    });
}

template <size_t VSize>
int countPuyos(const int field[][VSize]) {
  return countCell(field, [](int cell) {
      return cell != TEST_PUYO_COLOR_EMPTY;
    });
}

}

COMAI_HI::COMAI_HI()
{
    cchai = 0;
    hukks = 0;
    conaa = 0;
    nexaa = 0;
    maxchais = 0;
    for (int i = 0; i < 22; i++) {
        para[i] = 0;
    }
    myf_kosuu = 0;
    saisoku_flag = saisoku_point;
    aite_hakka_rensa = 0;
    aite_hakka_nokori = 0;
    aite_hakka_zenkesi = 0;
    aite_hakka_kosuu = 0;
    nocc_aite_rensa_score = 0;
    aite_rensa_score = 0;
    aite_rensa_score_cc = 0;
    key_ee = 1;
    aite_hakkaji_score = 0;
    aite_hakka_jamako = 0;
    aite_hakka_honsen = 0;
    aite_puyo_uki = 0;
    aite_hakka_quick = 0;
    kougeki_on = 0;
    kougeki_edge = 0;
    kougeki_iryoku = 0;
    one_tanpatu = 1;
    score_max = 0;
    mmmax = -1;
    score_aa = -10;
    aa_max_score = 0;
    hakkatime = 0;
    numg = 0;

    memset(katax, 0, sizeof(katax));
    memset(katay, 0, sizeof(katay));
    memset(kko, 0, sizeof(kko));
    memset(kinsi_a, 0, sizeof(kinsi_a));
    memset(kinsi_b, 0, sizeof(kinsi_b));
    memset(jakkin_a, 0, sizeof(jakkin_a));
    memset(jakkin_b, 0, sizeof(jakkin_b));
    memset(tankinko, 0, sizeof(tankinko));
    memset(jatako, 0, sizeof(jatako));
    read_template();
}

COMAI_HI::~COMAI_HI()
{
}

void COMAI_HI::aite_attack_nokori(int hakata)
{
    aite_hakka_nokori = aite_hakka_rensa - (hakata - hakkatime + 30) / 40;
}

// TODO: Refactor each method independently, and reunion all files.
#include "aite_rensa_end.cc"
#include "aite_hyouka.cc"
#include "is_enemy_start_rensa.cc"  // done
#include "ref.cc"
#include "hyouka.cc"
#include "syou.cc"
#include "saiki.cc"
#include "saiki_2.cc"
#include "saiki_3.cc"
#include "tobashi_hantei_a.cc"
#include "tobashi_hantei_b.cc"
#include "setti_puyo.cc"
#include "hon_syoukyo.cc"
#include "simulate_chain.cc"  // done
#include "setti_puyo_1.cc"
#include "chousei_syoukyo.cc"
#include "chousei_syoukyo_2.cc"
#include "chousei_syoukyo_3.cc"
#include "chousei_syoukyo_sc.cc"
#include "gtr.cc"
#include "read_template.cc"
#include "pre_hyouka.cc"
