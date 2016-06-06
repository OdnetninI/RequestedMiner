#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__

class GameState {
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;
    virtual ~GameState() {}
};

#endif // __GAMESTATE_HPP__
