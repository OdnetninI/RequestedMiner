// TODO: REMOVE THIS
#ifndef __ENTITYMANAGER_HPP__
#define __ENTITYMANAGER_HPP__

#include "Entity.hpp"
#include <list>
#include <SFML/Graphics.hpp>

class EntityManager {
  private:
    std::list<Entity*> entities;
    std::list<Entity*>::iterator it;
  public:
    EntityManager();
    ~EntityManager();
    uint16_t size();
    void insert(Entity* entity);
    Entity* create(int32_t x, int32_t y, uint16_t w, uint16_t h, sf::Texture* texture, uint16_t tx = 0, uint16_t ty = 0);
    void update();
    void remove(Entity* entity);
    Entity* next();
    void rewind();
    Entity* getCurrent();
    void draw(sf::RenderWindow* window);
};

#endif // __ENTITYMANAGER_HPP__
