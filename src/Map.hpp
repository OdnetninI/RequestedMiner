// Copyright (c) OdnetninI 2016-06-03
#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <cstdint>
#include <list>
#include <SFML/Graphics.hpp>
#include "TiledScreen.hpp"

class Map {
	private:
		sf::Vector2u** up[UP_LAYERS];
		sf::Vector2u** down[DOWN_LAYERS];

		uint64_t w,h;
		void loadFromFile (const char* filename, sf::Vector2u** data);

	public:
		uint64_t minX, minY, maxX, maxY;
		std::list<Map*> adyacentes;

		Map(uint64_t minX, uint64_t maxX, uint64_t minY, uint64_t maxY);
		~Map();
		sf::Vector2u getTile (bool up, uint16_t l, uint64_t x, uint16_t y);
		void addAyacente (Map* m);
		void load (bool up, uint16_t layer, const char* filename);
};

#endif // __MAP_HPP__
