#include "Camera.hpp"

void Camera::setPosition(sf::Vector2<uint64_t> pos) {
  this->position = pos;
}

void Camera::setPosition(uint64_t x, uint64_t y) {
  this->position.x = x;
  this->position.y = y;
}

void Camera::move(uint64_t x, uint64_t y) {
  this->position.x += x;
  this->position.y += y;
}

void Camera::lockEntity(MapEntity* entity) {
  this->lockedEntity = entity;
}

void Camera::unlockEntity() {
  this->lockedEntity = nullptr;
}

void Camera::update() {
  if (this->lockedEntity != nullptr)
    this->position = this->lockedEntity->getPosition();
}

sf::Vector2<uint64_t> Camera::getPosition() {
  return this->position;
}

uint64_t Camera::getX(){
  return this->position.x;
}

uint64_t Camera::getY(){
  return this->position.y;
}
