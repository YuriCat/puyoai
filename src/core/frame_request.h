#ifndef CORE_FRAME_REQUEST_H_
#define CORE_FRAME_REQUEST_H_

#include <string>

#include "core/core_field.h"
#include "core/game_result.h"
#include "core/kumipuyo_pos.h"
#include "core/kumipuyo_seq.h"
#include "core/player.h"
#include "core/user_event.h"

struct FrameRequestHeader {
    explicit FrameRequestHeader(uint32_t size = 0) : size(size) {}

    uint32_t size;
};

struct PlayerFrameRequest {
    PlainField field;
    KumipuyoSeq kumipuyoSeq;
    KumipuyoPos kumipuyoPos;
    UserEvent event;
    int score = 0;
    int ojama = 0;
};

struct FrameRequest {
    static FrameRequest parsePayload(const char* payload, size_t size);

    std::string toString() const;
    std::string toDebugString() const;

    bool isValid() const { return frameId != -1; }
    bool shouldInitialize() const { return frameId == 1; }
    bool hasGameEnd() const { return gameResult != GameResult::PLAYING; }

    const PlayerFrameRequest& myPlayerFrameRequest() const { return playerFrameRequest[0]; }
    const PlayerFrameRequest& enemyPlayerFrameRequest() const { return playerFrameRequest[1]; }

    int frameId = -1;
    GameResult gameResult = GameResult::PLAYING;
    bool matchEnd = false;
    PlayerFrameRequest playerFrameRequest[NUM_PLAYERS];
};

#endif
