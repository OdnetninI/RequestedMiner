
#ifndef __MAPENTITY_HPP__
#define __MAPENTITY_HPP__

#include <SFML/Graphics.hpp>
#include "Entity/AnimatedEntity.hpp"

class Camera;

class MapEntity {
  protected:
    AnimatedEntity entity;
    Camera* camera;
    sf::Vector2<uint64_t> position;
    sf::Vector2<uint16_t> fixed;

  public:
    MapEntity();
    ~MapEntity();
    void setCamera(Camera* camera);
    void setPosition(sf::Vector2<uint64_t> pos);
    void setPosition(uint64_t x, uint64_t y);
    void move(uint64_t x, uint64_t y);
    virtual void update();
    sf::Vector2<uint64_t> getPosition();

    // Return Real Position
    uint64_t getX();
    uint64_t getY();

    // Debug Like
    AnimatedEntity& getEntity();
};
#endif // __MAPENTITY_HPP__
