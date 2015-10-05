#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <iostream>

template<typename T, size_t x, size_t y = x>
class WorldMap
{
public:
	WorldMap<T, x, y>() : data_(T[x][y])

private:
	T[x][y] data_;
};

#endif