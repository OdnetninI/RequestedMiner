#ifndef __MAPCHARACTER_HPP__
#define __MAPCHARACTER_HPP__

#include "MapEntity.hpp"
#include "Animation.hpp"

class MapCharacter : public MapEntity {
  private:
    uint8_t dir;
    uint8_t look;

    bool isAligned();

    Animation* walking[4];
    Animation* stand[4];

  public:
    MapCharacter();
    void update();
    void lookAt(uint8_t dir);
    void moveTo(uint8_t dir);
    uint8_t getLook();
    uint8_t getDir();
    void setWalkingAnimation (uint8_t dir, Animation* anim);
    void setStandAnimation (uint8_t dir, Animation* anim);
};
#endif // __MAPCHARACTER_HPP__
