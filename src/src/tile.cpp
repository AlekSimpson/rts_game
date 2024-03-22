#include <cstdlib>
#include "../include/tile.h"
#include "../../lib/raylib.h"
#include "../../lib/raymath.h"

Tile::Tile() {
  x = 0;
  y = 0;
  occupied = false;
  textureFilePath = "../../assets/tilemap-separated.png";
  tileType = WATER;
  setTextureSource();
}

Tile::Tile(int _x, int _y, bool o, Rectangle ts, TileType tt) {
  x = _x;
  y = _y;
  occupied = o;
  textureFilePath = "/Users/aleksimpson/Desktop/projects/rts_game/assets/tilemap-separated.png";
  textureSource = ts;
  tileType = tt;
}

Tile::Tile(int _x, int _y, bool o, TileType tt) {
  x = _x;
  y = _y;
  occupied = o;
  textureFilePath = "/Users/aleksimpson/Desktop/projects/rts_game/assets/tilemap-separated.png";
  tileType = tt;
  setTextureSource();
}

int Tile::getTileX() {
  return x;
}

int Tile::getTileY() {
  return y;
}

bool Tile::isOccupied() {
  return occupied;
}

Texture2D Tile::loadTexture() {
  return LoadTexture(textureFilePath.c_str());
}

Rectangle Tile::getTextureSource() {
  return textureSource;
}

void Tile::setTextureSource() {
  Rectangle LANDRECT = Rectangle{32, 32, 16, 16};
  switch (tileType) {
    case LAND:
      textureSource = LANDRECT;
      break;
    case WATER:
      textureSource = Rectangle{96, 64, 16, 16};
      break;
    case ROAD:
      textureSource = LANDRECT;
      break;
    case MOUNTAIN:
      textureSource = LANDRECT;
      break;
    case CITY:
      textureSource = LANDRECT;
      break;
    case PORT:
      textureSource = LANDRECT;
      break;
    default:
      textureSource = LANDRECT;
      break;
  }
}

bool Tile::isTileType(TileType queryType) {
  return tileType == queryType;
}

TileType Tile::getTileType() {
  return tileType;
}

bool Tile::operator==(const Tile& other) {
  return tileType == other.tileType;
}

bool Tile::operator!=(const Tile& other) {
  return tileType != other.tileType;
}

void Tile::render() {
  Texture2D tileTexture = loadTexture();
  DrawTextureRec(tileTexture, textureSource, {static_cast<float>(x), static_cast<float>(y)}, RAYWHITE);
}


