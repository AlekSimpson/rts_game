#ifndef TILE_H
#define TILE_H

#include <cstdlib>
#include <string>
#include "../lib/raylib.h"
#include "../lib/raymath.h"

typedef enum {
  WATER,
  LAND,
  ROAD,
  MOUNTAIN,
  CITY,
  RUIN,
  PORT,
  NIL // for errors perhaps
} TileType;

class Tile {
private:
  int x;
  int y;
  bool occupied;
  std::string textureFilePath;
  Rectangle textureSource;
  TileType tileType; 

public:
  Tile();
  Tile(int x, int y, bool occupied, Rectangle ts, TileType tt);
  Tile(int x, int y, bool occupied, TileType tt);
  // ~Tile();
  
  int getTileX();
  int getTileY();
  bool isOccupied();
  Texture2D loadTexture();
  bool isTileType(TileType queryType);
  TileType getTileType();
  void render();
  Rectangle getTextureSource();
  void setTextureSource(); 

  bool operator==(const Tile& other);
  bool operator!=(const Tile& other);
};

#endif
