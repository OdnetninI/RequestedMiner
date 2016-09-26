#include "MapEventManager.hpp"

MapEventManager::MapEventManager() {
  this->eventMap.clear();
}

MapEventManager::~MapEventManager() {
  for (auto i = this->eventMap.begin(); i != this->eventMap.end(); ++i)
    delete i->second;
}

void MapEventManager::add(MapEvent* event) {
  MapVectorPos paux = event->getPos();
  auto aux = this->eventMap.find(paux);
  if (aux != this->eventMap.end()) return; // Use logger or error to report this (duplicate event)
  this->eventMap.insert({paux, event});
}

void MapEventManager::remove(MapEvent* event) {
  auto i = this->eventMap.begin();
  for (;i != this->eventMap.end() && i->second != event; ++i);
  this->eventMap.erase(i);
  delete event;
}

void MapEventManager::remove(MapVectorPos pos) {
  auto aux = this->eventMap.find(pos);
  if (aux == this->eventMap.end()) return; // Use logger or error to report this (non existing event)
  delete aux->second;
  this->eventMap.erase(aux);
}

void MapEventManager::remove(uint64_t x, uint64_t y) {
  this->remove({x,y});
}

MapEvent* MapEventManager::find(MapVectorPos pos) {
  auto aux = this->eventMap.find(pos);
  if (aux == this->eventMap.end()) return nullptr;
  return aux->second;
}

MapEvent* MapEventManager::find(uint64_t x, uint64_t y) {
  return this->find({x,y});
}

int operator<(const MapVectorPos& obj, const MapVectorPos& obj2) {
 if (obj.x < obj2.x || obj.y < obj2.y) return -1;
 return 0;
}
