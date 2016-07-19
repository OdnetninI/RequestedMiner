#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "MapCharacter.hpp"

class Controller {
  private:
    MapCharacter* chara;
    bool movementLocked;

  public:
    Controller();
    void lockMovement();
    void unlockMovement();
    void setCharacter(MapCharacter* character);
    void update();
};
#endif // __CONTROLLER_HPP__
