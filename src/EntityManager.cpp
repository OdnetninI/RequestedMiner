#include "EntityManager.hpp"

EntityManager::EntityManager() {
  this->entities.clear();
}

EntityManager::~EntityManager() {
  for (auto i = this->entities.begin(); i != this->entities.end(); i++)
    delete *i;
}

uint16_t EntityManager::size() {
  return this->entities.size();
}

void EntityManager::insert(Entity* entity) {
  this->entities.push_back(entity);
}

void EntityManager::remove(Entity* entity) {
  for (auto i = this->entities.begin(); i != this->entities.end(); i++) {
    if (*i == entity) {
      delete entity;
      this->entities.erase(i);
    }
  }
}

void EntityManager::update() {
  for (auto i = this->entities.begin(); i != this->entities.end(); i++)
    (*i)->update();
}

void EntityManager::rewind() {
  this->it = this->entities.begin();
}

Entity* EntityManager::next() {
  Entity* t = *it;
  if (it == this->entities.end()) return nullptr;
  it++;
  return t;
}

Entity* EntityManager::getCurrent() {
  if (it == this->entities.end()) return nullptr;
  return *it;
}

void EntityManager::draw(sf::RenderWindow* window) {
  for (auto i = this->entities.begin(); i != this->entities.end(); i++)
    (*i)->render(window);
}
