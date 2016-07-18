
#ifndef __MAPENTITY_HPP__
#define __MAPENTITY_HPP__

#include <SFML/Graphics.hpp>
#include "AnimatedEntity.hpp"

class Camera;

class MapEntity {
  private:
    AnimatedEntity entity;
    Camera* camera;
    sf::Vector2<uint64_t> position;

  public:
    MapEntity();
    ~MapEntity();
    void setCamera(Camera* camera);
    void setPosition(sf::Vector2<uint64_t> pos);
    void move(uint64_t x, uint64_t y);
    void update();
    sf::Vector2<uint64_t> getPosition();

    // Debug Like
    AnimatedEntity& getEntity();
};
#endif // __MAPENTITY_HPP__
