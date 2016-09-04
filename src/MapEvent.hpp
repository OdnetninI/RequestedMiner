#ifndef __MAPEVENT_HPP__
#define __MAPEVENT_HPP__

// ¿Map Event Controller must be on other thread?

#include "MapVectorPosition.hpp"
#include "Logger.hpp"

class MapEvent {
  private:
    MapVectorPos eventPosition;
  public:
    // TESTING
    void whenMapLoad() {Logger::Instance() << "Loaded\n";}
    void whenTalked ()  {Logger::Instance() << "Talked\n";}
    void whenWalked() {Logger::Instance() << "Don't stand on me\n";}
    void whenMapUnload() {Logger::Instance() << "UnLoaded\n";}
    /*
    virtual ~MapEvent() {}
    virtual void whenMapLoad() = 0;
    virtual void whenTalked () = 0;
    virtual void whenWalked() = 0;
    virtual void whenMapUnload() = 0;*/
    MapVectorPos getPos() {
      return eventPosition;
    }
    void setPos (MapVectorPos pos) {
      eventPosition = pos;
    }
    void setPos (uint64_t x, uint64_t y) {
      eventPosition.x = x;
      eventPosition.y = y;
    }
};
#endif // __MAPEVENT_HPP__
