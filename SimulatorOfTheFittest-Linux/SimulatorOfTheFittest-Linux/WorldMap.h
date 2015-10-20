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
	virtual std::vector<Actor*> getAllActors() = 0;
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
		moveAll();
	}

	void moveAll()
	{
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{

				// get actor array from current area
				std::vector<Actor*>* actors = area->getActors();
				// get end of actor vector
				auto end = actors->end();

				for (auto it = actors->begin(); it != actors->end(); )
				{
					if (myHelper::IsType<Plant, Actor>(*it) == false)
					{
						auto a = static_cast<Animal*>(*it);
						if ((a->getHasEaten() == false) && (a->getHasMoved() == false))
						{
							a->setHasMoved(true);

							if (std::next(area) != row->end())
							{
								// move animal to next array in current row
								std::next(area)->getActors()->push_back(std::move(a));
							}
							else
							{
								if (std::next(row) != data_.end())
								{
									// move animal to first array in next row
									std::next(row)->begin()->getActors()->push_back(std::move(a));
								}
								else
								{
									// move animal to first area in first row
									data_.begin()->begin()->getActors()->push_back(std::move(a));
								}
							}
							// erase animal from current area
							it = actors->erase(it);
						}
						else
						{
							// increment iterator
							it++;
						}
					}
					else
					{
						// increment iterator
						it++;
					}


				}

				area->generateRandomActors();
			}
		}
	}

	void printAllActors()
	{
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{
				area->printAllActors();
			}
		}

	}

	std::vector<Actor*> getAllActors()
	{
		// create an empty vector to add all actos to
		auto result = std::vector<Actor*>();
		// add actors
		for (auto row = data_.begin(); row != data_.end(); row++)
		{
			for (auto area = row->begin(); area != row->end(); area++)
			{
				auto temp = area->getAllActors();
				result.insert(result.end(), temp.begin(), temp.end());
			}
		}

		return result;
	}
private:
	std::array<std::array<Area, X>, Y> data_{};
};

struct GetWorldMap
{
	static WorldMapHolder* getWorldMap(int p1, int p2)
	{
		if (p1 == 1 && p2 == 1)	return new WorldMap<Area, 1>();
		else if (p1 == 1 && p2 == 2) return new WorldMap<Area, 1, 2>();
		else if (p1 == 1 && p2 == 3) return new WorldMap<Area, 1, 3>();
		else if (p1 == 1 && p2 == 4) return new WorldMap<Area, 1, 4>();
		else if (p1 == 1 && p2 == 5) return new WorldMap<Area, 1, 5>();
		else if (p1 == 1 && p2 == 6) return new WorldMap<Area, 1, 6>();
		else if (p1 == 1 && p2 == 7) return new WorldMap<Area, 1, 7>();
		else if (p1 == 1 && p2 == 8) return new WorldMap<Area, 1, 8>();
		else if (p1 == 1 && p2 == 9) return new WorldMap<Area, 1, 9>();
		else if (p1 == 1 && p2 == 10) return new WorldMap<Area, 1, 10>();

		else if (p1 == 2 && p2 == 1) return new WorldMap<Area, 2, 1>();
		else if (p1 == 2 && p2 == 2) return new WorldMap<Area, 2, 2>();
		else if (p1 == 2 && p2 == 3) return new WorldMap<Area, 2, 3>();
		else if (p1 == 2 && p2 == 4) return new WorldMap<Area, 2, 4>();
		else if (p1 == 2 && p2 == 5) return new WorldMap<Area, 2, 5>();
		else if (p1 == 2 && p2 == 6) return new WorldMap<Area, 2, 6>();
		else if (p1 == 2 && p2 == 7) return new WorldMap<Area, 2, 7>();
		else if (p1 == 2 && p2 == 8) return new WorldMap<Area, 2, 8>();
		else if (p1 == 2 && p2 == 9) return new WorldMap<Area, 2, 9>();
		else if (p1 == 2 && p2 == 10) return new WorldMap<Area, 2, 10>();

		else if (p1 == 3 && p2 == 1) return new WorldMap<Area, 3, 1>();
		else if (p1 == 3 && p2 == 2) return new WorldMap<Area, 3, 2>();
		else if (p1 == 3 && p2 == 3) return new WorldMap<Area, 3, 3>();
		else if (p1 == 3 && p2 == 4) return new WorldMap<Area, 3, 4>();
		else if (p1 == 3 && p2 == 5) return new WorldMap<Area, 3, 5>();
		else if (p1 == 3 && p2 == 6) return new WorldMap<Area, 3, 6>();
		else if (p1 == 3 && p2 == 7) return new WorldMap<Area, 3, 7>();
		else if (p1 == 3 && p2 == 8) return new WorldMap<Area, 3, 8>();
		else if (p1 == 3 && p2 == 9) return new WorldMap<Area, 3, 9>();
		else if (p1 == 3 && p2 == 10) return new WorldMap<Area, 3, 10>();

		else if (p1 == 4 && p2 == 1) return new WorldMap<Area, 4, 1>();
		else if (p1 == 4 && p2 == 2) return new WorldMap<Area, 4, 2>();
		else if (p1 == 4 && p2 == 3) return new WorldMap<Area, 4, 3>();
		else if (p1 == 4 && p2 == 4) return new WorldMap<Area, 4, 4>();
		else if (p1 == 4 && p2 == 5) return new WorldMap<Area, 4, 5>();
		else if (p1 == 4 && p2 == 6) return new WorldMap<Area, 4, 6>();
		else if (p1 == 4 && p2 == 7) return new WorldMap<Area, 4, 7>();
		else if (p1 == 4 && p2 == 8) return new WorldMap<Area, 4, 8>();
		else if (p1 == 4 && p2 == 9) return new WorldMap<Area, 4, 9>();
		else if (p1 == 4 && p2 == 10) return new WorldMap<Area, 4, 10>();

		else if (p1 == 5 && p2 == 1) return new WorldMap<Area, 5, 1>();
		else if (p1 == 5 && p2 == 2) return new WorldMap<Area, 5, 2>();
		else if (p1 == 5 && p2 == 3) return new WorldMap<Area, 5, 3>();
		else if (p1 == 5 && p2 == 4) return new WorldMap<Area, 5, 4>();
		else if (p1 == 5 && p2 == 5) return new WorldMap<Area, 5, 5>();
		else if (p1 == 5 && p2 == 6) return new WorldMap<Area, 5, 6>();
		else if (p1 == 5 && p2 == 7) return new WorldMap<Area, 5, 7>();
		else if (p1 == 5 && p2 == 8) return new WorldMap<Area, 5, 8>();
		else if (p1 == 5 && p2 == 9) return new WorldMap<Area, 5, 9>();
		else if (p1 == 5 && p2 == 10) return new WorldMap<Area, 5, 10>();

		else if (p1 == 6 && p2 == 1) return new WorldMap<Area, 6, 1>();
		else if (p1 == 6 && p2 == 2) return new WorldMap<Area, 6, 2>();
		else if (p1 == 6 && p2 == 3) return new WorldMap<Area, 6, 3>();
		else if (p1 == 6 && p2 == 4) return new WorldMap<Area, 6, 4>();
		else if (p1 == 6 && p2 == 5) return new WorldMap<Area, 6, 5>();
		else if (p1 == 6 && p2 == 6) return new WorldMap<Area, 6, 6>();
		else if (p1 == 6 && p2 == 7) return new WorldMap<Area, 6, 7>();
		else if (p1 == 6 && p2 == 8) return new WorldMap<Area, 6, 8>();
		else if (p1 == 6 && p2 == 9) return new WorldMap<Area, 6, 9>();
		else if (p1 == 6 && p2 == 10) return new WorldMap<Area, 6, 10>();

		else if (p1 == 7 && p2 == 1) return new WorldMap<Area, 7, 1>();
		else if (p1 == 7 && p2 == 2) return new WorldMap<Area, 7, 2>();
		else if (p1 == 7 && p2 == 3) return new WorldMap<Area, 7, 3>();
		else if (p1 == 7 && p2 == 4) return new WorldMap<Area, 7, 4>();
		else if (p1 == 7 && p2 == 5) return new WorldMap<Area, 7, 5>();
		else if (p1 == 7 && p2 == 6) return new WorldMap<Area, 7, 6>();
		else if (p1 == 7 && p2 == 7) return new WorldMap<Area, 7, 7>();
		else if (p1 == 7 && p2 == 8) return new WorldMap<Area, 7, 8>();
		else if (p1 == 7 && p2 == 9) return new WorldMap<Area, 7, 9>();
		else if (p1 == 7 && p2 == 10) return new WorldMap<Area, 7, 10>();

		else if (p1 == 8 && p2 == 1) return new WorldMap<Area, 8, 1>();
		else if (p1 == 8 && p2 == 2) return new WorldMap<Area, 8, 2>();
		else if (p1 == 8 && p2 == 3) return new WorldMap<Area, 8, 3>();
		else if (p1 == 8 && p2 == 4) return new WorldMap<Area, 8, 4>();
		else if (p1 == 8 && p2 == 5) return new WorldMap<Area, 8, 5>();
		else if (p1 == 8 && p2 == 6) return new WorldMap<Area, 8, 6>();
		else if (p1 == 8 && p2 == 7) return new WorldMap<Area, 8, 7>();
		else if (p1 == 8 && p2 == 8) return new WorldMap<Area, 8, 8>();
		else if (p1 == 8 && p2 == 9) return new WorldMap<Area, 8, 9>();
		else if (p1 == 8 && p2 == 10) return new WorldMap<Area, 8, 10>();

		else if (p1 == 9 && p2 == 1) return new WorldMap<Area, 9, 1>();
		else if (p1 == 9 && p2 == 2) return new WorldMap<Area, 9, 2>();
		else if (p1 == 9 && p2 == 3) return new WorldMap<Area, 9, 3>();
		else if (p1 == 9 && p2 == 4) return new WorldMap<Area, 9, 4>();
		else if (p1 == 9 && p2 == 5) return new WorldMap<Area, 9, 5>();
		else if (p1 == 9 && p2 == 6) return new WorldMap<Area, 9, 6>();
		else if (p1 == 9 && p2 == 7) return new WorldMap<Area, 9, 7>();
		else if (p1 == 9 && p2 == 8) return new WorldMap<Area, 9, 8>();
		else if (p1 == 9 && p2 == 9) return new WorldMap<Area, 9, 9>();
		else if (p1 == 9 && p2 == 10) return new WorldMap<Area, 9, 10>();

		else if (p1 == 10 && p2 == 1) return new WorldMap<Area, 10, 1>();
		else if (p1 == 10 && p2 == 2) return new WorldMap<Area, 10, 2>();
		else if (p1 == 10 && p2 == 3) return new WorldMap<Area, 10, 3>();
		else if (p1 == 10 && p2 == 4) return new WorldMap<Area, 10, 4>();
		else if (p1 == 10 && p2 == 5) return new WorldMap<Area, 10, 5>();
		else if (p1 == 10 && p2 == 6) return new WorldMap<Area, 10, 6>();
		else if (p1 == 10 && p2 == 7) return new WorldMap<Area, 10, 7>();
		else if (p1 == 10 && p2 == 8) return new WorldMap<Area, 10, 8>();
		else if (p1 == 10 && p2 == 9) return new WorldMap<Area, 10, 9>();
		else if (p1 == 10 && p2 == 10) return new WorldMap<Area, 10, 10>();

		else if (p1 == 20 && p2 == 20) return new WorldMap<Area, 20, 20>();
		else if (p1 == 30 && p2 == 30) return new WorldMap<Area, 30, 30>();
		else if (p1 == 40 && p2 == 40) return new WorldMap<Area, 40, 40>();
		else if (p1 == 50 && p2 == 50) return new WorldMap<Area, 50, 50>();
		else if (p1 == 60 && p2 == 60) return new WorldMap<Area, 60, 60>();
		else if (p1 == 70 && p2 == 70) return new WorldMap<Area, 70, 70>();
		else if (p1 == 80 && p2 == 80) return new WorldMap<Area, 80, 80>();
		else if (p1 == 90 && p2 == 90) return new WorldMap<Area, 90, 90>();
		else if (p1 == 100 && p2 == 100) return new WorldMap<Area, 100, 100>();

		// Insert custom map sizes here

		
		else
		{
			std::cout << "The map size " << p1 << " and " << p2 << " is not available. You can add it in file WorldMap.h" << std::endl;
			std::cout << "A default 10 X 10 map has been chosen" << std::endl;
			return new WorldMap<Area, 10, 10>();
		}

	}
};

#endif