#include <cstdlib>

#include "../../lib/raylib.h"
#include "../../lib/raymath.h"
#include "../include/map.h"
#include "../include/tile.h"
#include "../include/perlin.h"

GameMap::GameMap(int w, int h, double wl) {
  map = DoubleVector<Tile>(w, h);
  waterlevel = wl;
  mapTarget = LoadRenderTexture(w, h);

  initializeMap();
}

GameMap::GameMap() {
  map = DoubleVector<Tile>(50, 50);
  waterlevel = 0.4;
  mapTarget = LoadRenderTexture(50, 50);

  initializeMap();
}

GameMap::~GameMap() {
  UnloadRenderTexture(mapTarget);
}

double* GameMap::generateMapNoise() {
  double* noiseMap = new double[map.width() * map.height()];
  PerlinNoise pn = PerlinNoise();

  for (int y = 0; y < map.height(); y++) {
    for (int x = 0; x < map.width(); x++) {
      noiseMap[map.width() * x + y] = pn.noise(x * 10, y * 10, 0.8);
    }
  }

  return noiseMap;
}

Tile GameMap::createTile(int x, int y, double noise) {
  if (noise < waterlevel) {
    return Tile(x, y, false, WATER);
  }

  return Tile(x, y, false, LAND);
}

void GameMap::render() {
  DrawTextureRec(
    mapTarget.texture, 
    (Rectangle){0, 0, (float)mapTarget.texture.width, (float)mapTarget.texture.height}, 
    (Vector2){0, 0}, 
    WHITE
  );
}

void GameMap::initializeMap() {
  double* perlinNoiseMap = generateMapNoise();
  int currNoise;
  
  BeginTextureMode(mapTarget);
  ClearBackground(RAYWHITE);
  EndTextureMode();
  BeginTextureMode(mapTarget);
  for (int y = 0; y < map.height(); y++) {
    for (int x = 0; x < map.width(); x++) {
      currNoise = perlinNoiseMap[map.width() * x + y];
      map.set(x, y, createTile(x, y, currNoise));
      map.get(x, y)->render();
    }
  }
  EndTextureMode();
}
