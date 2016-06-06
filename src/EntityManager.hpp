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
    void update();
    void remove(Entity* entity);
    Entity* next();
    void rewind();
    Entity* getCurrent();
    void draw(sf::RenderWindow* window);
};

#endif // __ENTITYMANAGER_HPP__
