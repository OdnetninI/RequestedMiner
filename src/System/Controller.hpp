#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "../Map/MapCharacter.hpp"

class Map;

class Controller {
  private:
    MapCharacter* chara;
    Map* actualmap;
    bool movementLocked;

  public:
    Controller();
    void lockMovement();
    void unlockMovement();
    void setCharacter(MapCharacter* character);
    void update();
    void setActualMap(Map* map) {actualmap = map;}
};
#endif // __CONTROLLER_HPP__
