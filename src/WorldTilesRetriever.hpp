#ifndef __WORLDTILESRETRIEVER_HPP__
#define __WORLDTILESRETRIEVER_HPP__

#include <SFML/Graphics.hpp>

class WorldTilesRetriever {
  private:

  public:
    sf::Vector2u getTile (bool up, uint16_t l, uint64_t x, uint64_t y);

};

#endif // __WORLDTILESRETRIEVER_HPP__
