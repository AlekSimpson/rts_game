#include <iostream>
#include <cstdlib>
#include "../lib/raylib.h"
#include "../lib/raymath.h"
#include "../include/tile.h"
#include "../include/appstate.h"
using namespace std;

#define WIDTH 1500
#define HEIGHT 1000

void processInput(AppState&);
void update(AppState&);
void render(AppState&);

int main(int argc, char** argv) {
  InitWindow(WIDTH, HEIGHT, "Polytopia");
  SetTargetFPS(60);
  // leaving this here because of the raylib info spam filling up my terminal
  // see this link for more info on log levels: https://stackoverflow.com/questions/76491017/disable-raylib-iog-messages
  SetTraceLogLevel(LOG_ERROR);  

  bool quit = false;
  AppState gameState = AppState();
  Tile tile = Tile(WIDTH/2, HEIGHT/2, false, WATER);
  gameState.setStateDidChange(true);

  while (!WindowShouldClose() && !gameState.programIsDone()) {
    processInput(gameState);
    // update(gameState);
    render(gameState);
  }
  
  CloseWindow();

  return 0;
}

void processInput(AppState& state) {
  if (IsKeyDown(KEY_Q)) {
    state.quitProgram();
  }
}

void update(AppState& state) {
}

void render(AppState& state) {
  BeginDrawing();

  // draw background
  ClearBackground(WHITE);

  // draw test sprite
  state.getMap().render();

  EndDrawing();
  state.setStateDidChange(false);
}
