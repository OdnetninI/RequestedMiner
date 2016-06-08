#ifndef __ANIMATION_HPP__
#define __ANIMATION_HPP__

#include <cstdint>

typedef struct {
  uint16_t x, y;
} _frame;

#include <vector>
#include <SFML/Graphics.hpp>

class Animation {
  private:
    std::vector<_frame> frames;
    sf::Texture* texture;

  public:
    Animation();
    void setTexture(sf::Texture* texture);
    sf::Texture* getTexture();
    uint16_t size();
    uint16_t getTx(uint16_t frame);
    uint16_t getTy(uint16_t frame);
    void addFrame (uint16_t tx, uint16_t ty);
    void clear();
};

#endif // __ANIMATION_HPP__
