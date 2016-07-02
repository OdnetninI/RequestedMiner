#include "WorldTilesRetriever.hpp"

sf::Vector2u WorldTilesRetriever::getTile (bool up, uint16_t l, uint64_t x, uint64_t y) {
  if (up) return sf::Vector2u(0,0);
  if (l == 0) return sf::Vector2u(0,1);
  return sf::Vector2u(1,0);
}
