#ifndef __MAPEVENTMANAGER_HPP__
#define __MAPEVENTMANAGER_HPP__

#include <map> // Try to use unordered_map
#include "Map/MapVectorPosition.hpp"
#include "Map/MapEvent/MapEvent.hpp"

class MapEventManager {
  private:
    std::map<MapVectorPos, MapEvent*> eventMap;
  public:
    MapEventManager();
    ~MapEventManager();

    void add (MapEvent* event);

    // Calls Delete
    void remove (MapEvent* event);
    void remove (MapVectorPos pos);
    void remove (uint64_t x, uint64_t y);

    MapEvent* find (MapVectorPos pos);
    MapEvent* find (uint64_t x, uint64_t y);
};
#endif // __MAPEVENTMANAGER_HPP__


// This is only for Map Events, There will be other behaviour for NPCs
// or not, it depends on Hashmap write speed

/*
  1.Map Event = Funciones, abstractas. Son interfaces de eventos, mucha DATA.
  2.Map Event*= Puntero, 4/8 Bytes, acceso indirecto (Memoria Undead)

  Ventajas 1: rápido acceso, sin necesidad de nada más.
  Ventajas 2: libre albedrio de herencia

  Desventajas 1: Gran movimiento de Datos
  Desventajas 2: Memoria Muerta.

  Ganador: 1.
  ====================================================
    ALERTA: Cuidado con el manejo de memoria.
    Destruir el MapEventManager, destruirá la memoria
    de TODOS los map events.
  ====================================================
*/
