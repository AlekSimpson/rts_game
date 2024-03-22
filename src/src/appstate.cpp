#include <cmath>
#include <cstdlib>
#include <limits>
#include <vector>

#include "../lib/raylib.h"
#include "../lib/raymath.h"
#include "../include/appstate.h"
#include "../include/opponent.h"
#include "../include/player.h"
#include "../include/map.h"

/*
 * INFO CONSTRUCTORS
 *
 */

AppState::AppState() {
  currentTurn = 0;
  maxTurnsPassed = 0;

  programIsDone_ = false;
  gameIsOver_ = false;

  opsc = 1;
  opponents = new Opponent[1];
  opponents[0] = Opponent();

  GameMap gm = GameMap(30, 30, 50);
  gameMap = gm;
}

AppState::AppState(int width, int height, int turn, Player p, int opCount){
  mapWidth = width;
  mapHeight = height;
  currentTurn = turn;
  maxTurnsPassed = 0;

  programIsDone_ = false;
  gameIsOver_ = false;

  opsc = opCount;
  opponents = new Opponent[opsc];
  opponents[0] = Opponent();

  std::vector<Rectangle> rc;
  renderCache = rc;
  renderCache.push_back({80, 64, 16, 16}); // (5kn, 4kn, WATER), (2kn, 2kn, LAND)
  renderCache.push_back({32, 32, 16, 16});

  player = p;

  // GameMap gm = GameMap(width, height);
  gameMap = GameMap(width, height, 50);
}

//AppState::~AppState() {
//  delete[] opponents;
//}

/*
 * INFO SETTERS
 *
 */

void AppState::quitProgram() {
  programIsDone_ = true;
}

void AppState::setStateDidChange(bool value) {
  stateDidChange = value;
}

/*
 * INFO GETTERS
 *
 */

bool AppState::gameIsOver() {
  return gameIsOver_;
}

bool AppState::programIsDone() {
  return programIsDone_;
}

GameMap AppState::getMap() {
  return gameMap;
}

bool AppState::didStateChange() {
  return stateDidChange;
}

/*
 * INFO UTILITY
 *
 */

void AppState::toggleStateDidChange() {
  stateDidChange = (stateDidChange) ? false : true;
}

void AppState::nextTurn() {
  maxTurnsPassed += 1;
  // this will rotate the current turn for every agent in the game
  currentTurn = maxTurnsPassed % (1 + opsc);
}
