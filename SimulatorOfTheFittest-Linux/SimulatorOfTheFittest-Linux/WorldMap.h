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
	std::array<std::array<T, X>, Y> data_{};
};

template<size_t X, size_t Y>
class WorldMap<Area, X, Y> : public WorldMapHolder
{
public:	
	void printAll()
	{
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{
				std::cout << *area << std::endl;
			}
		}
	}

	void actAll()
	{
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{
				area->act();
			}
		}

		move();
	}

	void move()
	{
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{
				// get actor array from current area
				std::vector<Actor*>* actors = area->getActors();

				for (auto it = actors->begin(); it != actors->end(); it++)
				{
					if (myHelper::IsType<Plant, Actor>(*it) == false)
					{
						auto a = static_cast<Animal*>(*it);
						if (a->getHasEaten() == false && a->getHasMoved() == false)
						{
							a->setHasMoved(true);

							if (std::next(area) != row->end())
							{
								std::next(area)->getActors()->push_back(a);
							}
							else
							{
								if (std::next(row) != data_.end())
								{
									row->begin()->getActors()->push_back(a);
								}
								else
								{
									data_.begin()->begin()->getActors()->push_back(a);
								}
							}
						}
					}
				}
			}
		}
	}
private:
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