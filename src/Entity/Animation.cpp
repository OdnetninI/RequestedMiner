#include "Animation.hpp"

Animation::Animation() {

}

void Animation::addFrame(uint16_t tx, uint16_t ty) {
  _frame frame;
  frame.x = tx;
  frame.y = ty;
  this->frames.push_back(frame);
}

void Animation::setTexture(sf::Texture* texture) {
  this->texture = texture;
}

sf::Texture* Animation::getTexture() {
  return this->texture;
}

uint16_t Animation::size() {
  return this->frames.size();
}

uint16_t Animation::getTx(uint16_t frame) {
  if (frame >= this->size()) return 0;
  return this->frames[frame].x;
}

uint16_t Animation::getTy(uint16_t frame) {
  if (frame >= this->size()) return 0;
  return this->frames[frame].y;
}

void Animation::clear() {
  this->frames.clear();
}
