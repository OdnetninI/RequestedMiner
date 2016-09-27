#include "Map/MapVectorPosition.hpp"

int operator<(const MapVectorPos& obj, const MapVectorPos& obj2) {
  if (obj.x < obj2.x || obj.y < obj2.y) return -1;
  return 0;
}

MapVectorPos operator+(const MapVectorPos& obj, const MapVectorPos& obj2) {
  MapVectorPos pos;
  pos.x = obj.x + obj2.x;
  pos.y = obj.y + obj2.y;
  return pos;
}
