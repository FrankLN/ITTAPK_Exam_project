#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <iostream>
#include <array>
#include <vector>
#include <typeinfo>
#include "Area.h"

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
	void move() 
	{

	}
private:
	//T data_[X][Y];
	std::array<std::array<T, X>, Y> data_{};
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
		move();
		for (auto rows = data_.begin(); rows != data_.end(); rows++)
		{
			for (auto area = rows->begin(); area != rows->end(); area++)
			{
				area->printAllActors();
				std::cout << std::endl;
			}
		}
	}
	void move()
	{
		for (auto rows = data_.begin(); rows != data_.end(); rows++)
		{
			for (auto area = rows->begin(); area != rows->end(); area++)
			{
				std::vector<Animal*> animals;
				std::vector<Actor*>* actors = area->getActors();

				for (auto it = actors->begin(); it != actors->end(); it++)
				{
					if ((*it)->getName() != "Plant")
					{
						auto a = static_cast<Animal*>(*it);
						if (a->getHasEaten() == false && a->getHasMoved() == false)
						{
							a->setHasMoved(true);
							animals.push_back(a);
							std::next(area)->getActors()->push_back(a);
						}
					}
				}
			}
		}

		/*for (auto &rows : data_)
		{
			//for (auto area : rows)
			{
				std::vector<Animal*> animals;
				std::vector<Actor*>* actors = area.getActors();

				for (auto it = actors->begin(); it != actors->end(); it++)
				{
					if ((*it)->getName() != "Plant")
					{
						auto a = static_cast<Animal*>(*it);
						if (a->getHasEaten() == false && a->getHasMoved() == false)
						{
							animals.push_back(a);
						}
					}
				}
			}
		}*/
	}
private:
	//Area data_[X][Y];
	std::array<std::array<Area, X>, Y> data_{};
};

struct GetWorldMap
{
	static WorldMapHolder* getWorldMap(int p1, int p2)
	{
		return new WorldMap<Area, 1>();
	}
};

#endif