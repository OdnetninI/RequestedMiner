#include "Map/MapPosFinder.hpp"
#include "Map/Map.hpp"

MapPosFinder::MapPosFinder() {
  this->last = nullptr;
}

inline MapPosFinder::minYNode MapPosFinder::createB (Map* objeto) {
  minYNode nodo;
  nodo.objeto = objeto;
  nodo.minY = objeto->minY;
  return nodo;
}

inline bool MapPosFinder::isInside ( Map* m, uint64_t x, uint64_t y) {
  if (x < m->minX || x > m->maxX || y < m->minY || y > m->maxY) return false;
  return true;
}

Map* MapPosFinder::buscar (uint64_t x, uint64_t y) {

  if ( last != nullptr) {
    if (isInside(last, x, y)) return last;
    for (auto i = last->adyacentes.begin(); i != last->adyacentes.end(); i++)
      if (isInside(*i,x,y)) return *i;
  }

  auto i = lista.begin();
  if (x >= midX->minX) i = midX;
  while (i != lista.end() && i->minX <= x) i++;
  Map* o = nullptr;

  do {
    i--;
    if (i == lista.end())	return nullptr;

    auto j = i->lista.begin();
    if (y >= i->midY->minY) j = i->midY;
    while (j != i->lista.end() && j->minY <= y) j++;

    j--;
    if (j == i->lista.end()) o = nullptr;
    else {
      o = j->objeto;
      if (!isInside(o, x, y)) o = nullptr;
    }

  } while (o == nullptr && i != lista.begin());

  if (o == nullptr) return nullptr;
  last = o;
  return o;

}

void MapPosFinder::insertar (Map* o) {
  minYNode y = createB(o);
  auto i = lista.begin();
  while (i != lista.end() && i->minX < o->minX) i++;
  if (i == lista.end()) {
    minXNode nodo;
    nodo.minX = o->minX;
    nodo.lista.push_back(y);
    auto p = lista.insert(i,nodo);
    p->midY = std::next(p->lista.begin(), (int)p->lista.size()/2);
    midX = std::next(lista.begin(), (int)lista.size()/2);
    if (midX == lista.end()) midX--;
  }
  else if (i->minX == o->minX) {
    auto j = i->lista.begin();
    while (j != i->lista.end() && j->minY < o->minY) j++;
    if (j == i->lista.end()) {
      i->lista.insert(j, y);
      i->midY = std::next(i->lista.begin(), (int)i->lista.size()/2);
    }
    else if (j->minY == o->minY) return; // Inserted, Do Nothing
    else {
      i->lista.insert(j, y);
      i->midY = std::next(i->lista.begin(), (int)i->lista.size()/2);
    }
  }
  else {
    minXNode nodo;
    nodo.minX = o->minX;
    nodo.lista.push_back(y);
    auto p = lista.insert(i,nodo);
    p->midY = std::next(p->lista.begin(), (int)p->lista.size()/2);
    midX = std::next(lista.begin(), (int)lista.size()/2);
    if (midX == lista.end()) midX--;
  }
}
