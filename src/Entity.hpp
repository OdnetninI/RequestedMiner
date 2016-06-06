#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <SFML/Graphics.hpp>

class Entity {
  private:
    sf::RenderStates renderState;
    sf::Vertex vertex[4];
    int32_t x, y; // Screen Pos
    uint16_t w, h; // Dimensions
    uint16_t tx, ty; // Texture position
    bool stateUpdated;

  public:
    Entity();
    ~Entity();
    void setTexture(sf::Texture* texture);
    void setPosition(int32_t x, int32_t y);
    void setSize(uint16_t w, uint16_t h);
    void setTexturePos(uint16_t x, uint16_t y);
    void update();
    void render(sf::RenderWindow* window);
};

#endif // __ENTITY_HPP__
