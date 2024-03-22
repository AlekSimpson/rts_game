#ifndef APPSTATE_H
#define APPSTATE_H

#include <vector>

#include "../lib/raylib.h"
#include "../lib/raymath.h"
#include "../include/tile.h"
#include "../include/player.h"
#include "../include/opponent.h"
#include "../include/map.h"

class AppState {
private:
  int mapWidth;
  int mapHeight;
  int currentTurn;
  int maxTurnsPassed;
  bool gameIsOver_;
  bool programIsDone_;
  Opponent* opponents;
  int opsc;
  std::vector<Rectangle> renderCache;
  Player player;
  GameMap gameMap;
  bool stateDidChange;

public:
  /* INFO CONSTRUCTORS */
  AppState();
  // will generate opponents when created
  AppState(int, int, int, Player, int); 
  // ~AppState();

  /* INFO SETTERS */
  void quitProgram();
  void setStateDidChange(bool);

  /* INFO GETTERS */
  bool gameIsOver();
  bool programIsDone();
  GameMap getMap();
  bool didStateChange();

  /* INFO UTILITY */
  void nextTurn();
  void toggleStateDidChange();
};

#endif
