// Copyright (c) OdnetninI 2016-06-03
#ifndef __MAPPOSFINDER_HPP__
#define __MAPPOSFINDER_HPP__

#include <list>
#include <iterator>

class Map;

class MapPosFinder {
	private:
		Map* last;

		typedef struct {
			uint64_t minY;
			Map* objeto;
		} minYNode;

		typedef struct {
			uint64_t minX;
			std::list<minYNode> lista;
			std::list<minYNode>::iterator midY;
		} minXNode;

		std::list<minXNode> lista;
		std::list<minXNode>::iterator midX;

		minYNode createB (Map* objeto);
		bool isInside ( Map* m, uint64_t x, uint64_t y);

	public:
		MapPosFinder();
		Map* buscar (uint64_t x, uint64_t y);
		void insertar (Map* o);
};

#endif // __MAPPOSFINDER_HPP__
