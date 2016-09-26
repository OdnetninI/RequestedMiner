#include "AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity() {
  this->looped = true;
  this->playing = false;
  this->currentAnim = nullptr;
  this->timePerFrame = 0;
  this->currentTime = 0;
}

void AnimatedEntity::setAnimation(Animation* anim) {
  this->currentAnim = anim;
  this->setTexture(anim->getTexture());
  this->setFrame(0);
}

void AnimatedEntity::setFrame(uint16_t frame) {
  this->currentFrame = frame;
  if (this->currentAnim == nullptr) return;
  this->setTexturePos(this->currentAnim->getTx(frame), this->currentAnim->getTy(frame));
}

void AnimatedEntity::setLoop(bool loop) {
  this->looped = loop;
}

bool AnimatedEntity::isLooped() {
  return this->looped;
}

void AnimatedEntity::play() {
  this->playing = true;
}

void AnimatedEntity::pause() {
  this->playing = false;
}

void AnimatedEntity::stop() {
  this->playing = false;
  this->setFrame(0);
}

void AnimatedEntity::setTimePerFrame(uint16_t time) {
  this->timePerFrame = time;
}

uint16_t AnimatedEntity::getTimePerFrame() {
  return this->timePerFrame;
}

void AnimatedEntity::update() {
  Entity::update();
  if (this->playing && this->currentAnim != nullptr) {
    this->currentTime++;
    if (this->currentTime >= this->timePerFrame) {
      this->currentTime = 0;
      this->currentFrame++;
      if (this->currentFrame >= this->currentAnim->size()) {
        this->currentFrame = 0;
        if (!this->looped) this->playing = false;
      }
      this->setFrame(this->currentFrame);
    }
  }
}
