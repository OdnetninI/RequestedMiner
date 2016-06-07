#include "AnimationManager.hpp"

AnimationManager::AnimationManager() {

}

AnimationManager::~AnimationManager() {
  for (auto it = this->animations.begin(); it != this->animations.end(); it++)
    delete it->second;
}

void AnimationManager::add(std::string name, Animation* anim) {
  this->animations.insert(std::pair<std::string, Animation*>(name, anim));
}

void AnimationManager::remove(std::string name) {
  auto it = this->animations.find(name);
  if (it == this->animations.end()) return;
    delete it->second;
    this->animations.erase(it);
}

Animation* AnimationManager::get(std::string name) {
  auto it = this->animations.find(name);
  if (it == this->animations.end()) return nullptr;
  return it->second;
}
