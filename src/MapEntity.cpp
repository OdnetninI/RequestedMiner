#include "MapEntity.hpp"
#include "Camera.hpp"
#include "Game.hpp"

sf::Vector2<uint64_t> MapEntity::getPosition() {
  return this->position;
}

MapEntity::MapEntity() {
  camera = nullptr;
  fixed.x = 0;
  fixed.y = 0;
}

MapEntity::~MapEntity() {

}

void MapEntity::setCamera(Camera* camera) {
  this->camera = camera;
}

void MapEntity::update () {
  if (camera) {
    int32_t screenPosX = this->position.x - camera->getPosition().x - fixed.x;
    int32_t screenPosY = this->position.y - camera->getPosition().y - fixed.y;
    this->entity.setPosition(screenPosX, screenPosY);
    if (screenPosX < -this->entity.getW() || screenPosY < -this->entity.getH() || screenPosX > SCREEN_X || screenPosY > SCREEN_Y)
      this->entity.toRender(false);
    else this->entity.toRender(true);
  }
  this->entity.update();
}

AnimatedEntity& MapEntity::getEntity() {
  return entity;
}

void MapEntity::setPosition(sf::Vector2<uint64_t> pos) {
  position = pos;
}

void MapEntity::setPosition(uint64_t x, uint64_t y) {
  position.x = x;
  position.y = y;
}

void MapEntity::move(uint64_t x, uint64_t y) {
  position.x += x;
  position.y += y;
}


/*
1000,1000
 -------------------------
 |                       |
 |                       |
 |                       |
 -------------------------
ScreenPos = RealPos - Camera
1000 ------------------ 1000                0
1000 ------------------ 1001                -1
1001 ------------------ 1000                1
1000 ------------------ 1025                -25
1025 ------------------ 1000                25

*/

// TODO: Why Entity is X and Y and others are sf::Vector2<> ?
