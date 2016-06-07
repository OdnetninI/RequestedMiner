#ifndef __ANIMATEDENTITY_HPP__
#define __ANIMATEDENTITY_HPP__

#include "Entity.hpp"
#include "Animation.hpp"

class AnimatedEntity : public Entity {
  private:
    Animation* currentAnim;
    uint16_t currentFrame;
    bool looped;
    bool playing;
    uint16_t timePerFrame;
    uint16_t currentTime;

  public:
    AnimatedEntity();
    void setAnimation(Animation* anim);
    Animation* getAnimation();
    void setLoop(bool loop);
    bool isLooped();
    void play();
    void pause();
    void stop();
    bool isPaused();
    void setTimePerFrame(uint16_t time);
    void setFrame(uint16_t frame);
    uint16_t getTimePerFrame();
    void update();

};

#endif // __ANIMATEDENTITY_HPP__
