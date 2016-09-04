// Copyright (c) OdnetninI 2016-06-03
#ifndef __MAP_HPP__
#define __MAP_HPP__

// TODO: Rewrite
#include <cstdint>
#include <list>
#include <SFML/Graphics.hpp>
#include "TiledScreen.hpp"
#include "MapEventManager.hpp"

class Map {
	private:
		sf::Vector2u** up[UP_LAYERS];
		sf::Vector2u** down[DOWN_LAYERS];
		uint16_t animatedTimes;

		uint64_t w,h;
		void loadFromFile (const char* filename, sf::Vector2u** data);
		MapEventManager mapEventManager;

	public:
		uint64_t minX, minY, maxX, maxY;
		std::list<Map*> adyacentes;

		MapEventManager* getEventManager(); // ONLY FOR TESTING
		void checkEvent (uint64_t x, uint64_t y, uint8_t type);
		Map(uint64_t minX, uint64_t maxX, uint64_t minY, uint64_t maxY);
		~Map();
		sf::Vector2u getTile (bool up, uint16_t l, uint64_t x, uint16_t y);
		void setTile (bool up, uint16_t l, uint64_t x, uint16_t y, sf::Vector2u tile);
		uint16_t getAnimationTime ();
		void addAyacente (Map* m);
		void load (bool up, uint16_t layer, const char* filename);
		void update ();
};

#endif // __MAP_HPP__
