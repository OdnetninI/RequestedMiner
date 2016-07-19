#ifndef __MAPCHARACTER_HPP__
#define __MAPCHARACTER_HPP__

#include "MapEntity.hpp"

class MapCharacter : public MapEntity {
  private:
    uint8_t dir;
    uint8_t look;

    bool isAligned();

  public:
    MapCharacter();
    void update();
    void lookAt(uint8_t dir);
    void moveTo(uint8_t dir);
    uint8_t getLook();
    uint8_t getDir();
};
#endif // __MAPCHARACTER_HPP__
