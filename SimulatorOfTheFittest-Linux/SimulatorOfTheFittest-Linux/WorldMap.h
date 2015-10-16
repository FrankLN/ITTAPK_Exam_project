#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <iostream>
#include "Area.h"
#include <typeinfo>

class WorldMapHolder
{
public:
	virtual ~WorldMapHolder() {};
	virtual void printAll() = 0;
	virtual void actAll() = 0;
};

template<typename T, size_t X, size_t Y = X>
class WorldMap : public WorldMapHolder
{
public:	
	void printAll()
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				std::cout << data_[i][j] << std::endl;
			}
		}
	}

	void actAll()
	{
		std::cout << "actAll is not available for this type: " << typeid(T).name() << std::endl;
	}
private:
	T data_[X][Y];
};

template<size_t X, size_t Y>
class WorldMap<Area, X, Y> : public WorldMapHolder
{
public:	
	void printAll()
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				std::cout << data_[i][j] << std::endl;
			}
		}
	}

	void actAll()
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				data_[i][j].act();
			}
		}
	}
private:
	Area data_[X][Y];
};

struct GetWorldMap
{
	static WorldMapHolder* getWorldMap(int p1, int p2)
	{
		return new WorldMap<Area, 1>();
	}
};

#endif