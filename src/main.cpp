#include "Game.hpp"
#include "System/Logger.hpp"

void singletonCloser();

int main() {
  int returnValue = Game::Instance()->gameLoop();
  singletonCloser();
  return returnValue;
}

inline void singletonCloser() {
  Logger::destroy();
  Game::destroy();
}
