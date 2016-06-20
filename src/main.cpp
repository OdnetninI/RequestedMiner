#include "Game.hpp"
#include "Logger.hpp"

int main() {
  int returnValue = Game::Instance()->gameLoop();
  Logger::destroy();
  Game::destroy();
  return returnValue;
}
