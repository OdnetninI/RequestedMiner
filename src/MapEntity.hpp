#ifndef __MAPENTITY_HPP__
#define __MAPENTITY_HPP__

#include <SFML/Graphics.hpp>
#include "AnimatedEntity.hpp"

class Camera;

class MapEntity {
  private:
    Entity entity;
    Camera* camera;
    sf::Vector2<uint64_t> position;

  public:
    MapEntity();
    ~MapEntity();
    void setCamera(Camera* camera);
    void update();
    sf::Vector2<uint64_t> getPosition();

    // Debug Like
    Entity& getEntity();
};
#endif // __MAPENTITY_HPP__
