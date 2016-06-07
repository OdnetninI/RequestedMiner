#ifndef __ANIMATIONMANAGER_HPP__
#define __ANIMATIONMANAGER_HPP__

#include "Animation.hpp"
#include <map>
#include <string>

class AnimationManager {
  private:
    std::map<std::string, Animation*> animations;

  public:
    AnimationManager();
    ~AnimationManager();
    void add(std::string name, Animation* anim);
    void remove(std::string name);
    Animation* get(std::string name);
};

#endif // __ANIMATIONMANAGER_HPP__
