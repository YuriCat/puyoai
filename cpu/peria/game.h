#ifndef CPU_PERIA_GAME_H_
#define CPU_PERIA_GAME_H_

#include <string>

#include "base.h"
#include "player.h"

class Game {
 public:
  Game(const string& name);
  ~Game();

  // Input game status from the server.
  bool Input(const string& input);

  // Process and output commands.
  string Play();

 private:
  bool CheckDiff(const Player& prev, Player* player);

  string name_;
  scoped_ptr<Player> players_[2];
  int id_;  // Time frame
};

#endif  // CPU_PERIA_GAME_H_
