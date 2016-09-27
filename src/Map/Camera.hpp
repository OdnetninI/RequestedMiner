#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <SFML/Graphics.hpp>
#include "Map/MapEntity/MapEntity.hpp"

class Camera {
  private:
    sf::Vector2<uint64_t> position;
    MapEntity* lockedEntity = nullptr;

  public:
    void setPosition(sf::Vector2<uint64_t> pos);
    void setPosition(uint64_t x, uint64_t y);
    void move(uint64_t x, uint64_t y);
    void lockEntity(MapEntity* entity);
    void unlockEntity();
    void update();
    sf::Vector2<uint64_t> getPosition();
    uint64_t getX();
    uint64_t getY();
};
#endif // __CAMERA_HPP__
