#ifndef __MAPENTITY_HPP__
#define __MAPENTITY_HPP__

#include <SFML/Graphics.hpp>

class MapEntity {
  private:
    sf::Vector2<uint64_t> position;
  public:
    sf::Vector2<uint64_t> getPosition();
};
#endif // __MAPENTITY_HPP__
