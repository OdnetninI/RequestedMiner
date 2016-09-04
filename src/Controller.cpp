#include "Controller.hpp"
#include "Map.hpp"

Controller::Controller() {
  chara = nullptr;
  actualmap = nullptr;
  movementLocked = false;
}

void Controller::lockMovement() {
  movementLocked = true;
}

void Controller::unlockMovement() {
  movementLocked = false;
}

void Controller::setCharacter(MapCharacter* character) {
  chara = character;
}

#include "DirLook.hpp"
void Controller::update() {
  if (movementLocked) return;
  if (!chara) return;
  if (chara->getDir() != DIR_NONE) return;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && chara->getLook() == DIR_RIGHT)
    chara->moveTo(DIR_RIGHT);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && chara->getLook() == DIR_LEFT)
    chara->moveTo(DIR_LEFT);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && chara->getLook() == DIR_UP)
    chara->moveTo(DIR_UP);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && chara->getLook() == DIR_DOWN)
    chara->moveTo(DIR_DOWN);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && chara->getLook() != DIR_RIGHT)
    chara->lookAt(DIR_RIGHT);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && chara->getLook() != DIR_LEFT)
    chara->lookAt(DIR_LEFT);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && chara->getLook() != DIR_UP)
    chara->lookAt(DIR_UP);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && chara->getLook() != DIR_DOWN)
    chara->lookAt(DIR_DOWN);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
    if (actualmap) {
      int8_t ix = 0;
      int8_t iy = 0;
      if (chara->getLook() == DIR_RIGHT) ix=1;
      else if (chara->getLook() == DIR_LEFT) ix=-1;
      else if (chara->getLook() == DIR_DOWN) iy=1;
      else if (chara->getLook() == DIR_UP) iy=-1;
      uint64_t px = (chara->getX()+TILE_SIZE)/TILE_SIZE - actualmap->minY + ix;
      uint64_t py = (chara->getY()+TILE_SIZE)/TILE_SIZE - actualmap->minX + iy;
      if (actualmap->checkEvent(px, py, 0)) return;
    }
  }
}
