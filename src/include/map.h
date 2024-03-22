#ifndef MAP_H
#define MAP_H

#include "../include/tile.h"
#include "../include/player.h"
#include "../include/opponent.h"
#include "../include/map.h"
#include "../include/doublevector.hpp"

class GameMap {
private:
  DoubleVector<Tile> map;
  double waterlevel;
  RenderTexture2D mapTarget;
public:
  /* INFO: CONSTRUCTORS */
  GameMap();
  GameMap(int w, int h, double wl);
  ~GameMap();

  /* INFO: UTILITY */
  Tile createTile(int, int, double);
  double* generateMapNoise();
  void initializeMap();
  void render();
};

#endif
