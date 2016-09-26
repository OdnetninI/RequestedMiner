#include "MapCharacter.hpp"
#include "DirLook.hpp"
#include "../Game.hpp"

// NOTE: Speed must be divisor of TILE_SIZE
#define CHAR_SPEED 1

MapCharacter::MapCharacter() {
  dir = DIR_NONE;
  look = DIR_DOWN;
  for (uint8_t i = 0; i < 4; i++) {
    walking[i] = nullptr;
    stand[i] = nullptr;
  }
}

void MapCharacter::update() {
  MapEntity::update();
  if (dir == DIR_UP) move(0,-CHAR_SPEED);
  else if (dir == DIR_DOWN) move(0,CHAR_SPEED);
  else if (dir == DIR_LEFT) move(-CHAR_SPEED,0);
  else if (dir == DIR_RIGHT) move(CHAR_SPEED,0);
  if (dir != DIR_NONE && isAligned()) {
    // NOTE: temporal fix
    entity.stop();
    dir = DIR_NONE;
  }
}

void MapCharacter::lookAt(uint8_t dir) {
  this->look = dir;
  if (dir >= DIR_DOWN && dir <= DIR_RIGHT) {
    if (stand[dir-1]) {
      entity.setAnimation(stand[dir-1]);
      entity.play();
    }
  }
}

void MapCharacter::moveTo(uint8_t dir) {
  if (this->dir == DIR_NONE)
    this->dir = dir;
  if (dir >= DIR_DOWN && dir <= DIR_RIGHT) {
    if (walking[dir-1]) {
      entity.setAnimation(walking[dir-1]);
      entity.play();
    }
  }
}

void MapCharacter::setWalkingAnimation(uint8_t dir, Animation* anim) {
  if (dir >= DIR_DOWN && dir <= DIR_RIGHT)
    walking[dir-1] = anim;
}

void MapCharacter::setStandAnimation(uint8_t dir, Animation* anim) {
  if (dir >= DIR_DOWN && dir <= DIR_RIGHT)
    stand[dir-1] = anim;
}

bool MapCharacter::isAligned() {
  uint64_t x = position.x/TILE_SIZE;
  uint64_t y = position.y/TILE_SIZE;
  x = x * TILE_SIZE;
  y = y * TILE_SIZE;
  return ((position.x == x) && (position.y == y));
}

uint8_t MapCharacter::getLook() {
  return look;
}

uint8_t MapCharacter::getDir() {
  return dir;
}
