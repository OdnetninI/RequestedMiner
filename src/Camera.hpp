#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <SFML/Graphics.hpp>
#include "MapEntity.hpp"

class Camera {
  private:
    sf::Vector<uint64_t> position;
    MapEntity* lockedEntity;

  public:
    void setPosition(sf::Vector<uint64_t> pos);
    void setPosition(uint64_t x, uint64_t y);
    void move(uint64_t x, uint64_t y);
    void lockEntity(MapEntity* entity);
    sf::Vector<uint64_t> getPosition();
    uint64_t getX();
    uint64_t getY();
};
#endif // __CAMERA_HPP__
