#ifndef __MAPVECTORPOSITION_HPP__
#define __MAPVECTORPOSITION_HPP__

#include <cstdint>

// sf::Vector2 vs struct, whitch is better?
struct _mapVectorPostition {
  uint64_t x, y;
};
typedef struct _mapVectorPostition MapVectorPos;

int operator<(const MapVectorPos& obj, const MapVectorPos& obj2);

#endif // __MAPVECTORPOSITION_HPP__
