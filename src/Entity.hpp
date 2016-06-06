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
    bool doRender;

  public:
    Entity();
    ~Entity();
    void setTexture(sf::Texture* texture);
    void setPosition(int32_t x, int32_t y);
    int32_t getX();
    int32_t getY();
    void setSize(uint16_t w, uint16_t h);
    uint16_t getW();
    uint16_t getH();
    void setTexturePos(uint16_t x, uint16_t y);
    uint16_t getTx();
    uint16_t getTy();
    void update();
    void render(sf::RenderWindow* window);

    void toRender (bool doRender);
    bool getIfRender ();
};

#endif // __ENTITY_HPP__
