#include <random>
#include <boost/smart_ptr.hpp>

#include "Area.h"
#include "SharedHelperFunctions.h"

#define chance 60

Area::Area()
{
	std::random_device rd;
	seed_ = rd();
	
	srand(seed_);

	switch (rand() % 4)
	{
	case 0:
		name_ = "Forrest area";
		break;
	case 1:
		name_ = "Beach area";
		break;
	case 2:
		name_ = "Dessert area";
		break;
	case 3:
		name_ = "Flat area";
		break;
	default:
		name_ = "default Area";
		break;
	}

	actors_ = std::vector<Actor*>();
	generateRandomActors();
}

Area::~Area()
{
	/*for (int i = 0; i < actors_.size(); i++)
	{
		delete actors_[i];
	}*/
}

std::string Area::getName() const
{
	return name_;
}

int Area::getSeed() const
{
	return seed_;
}

int Area::getRandomNumber() const
{
	return rand();
}

void Area::generateRandomActors()
{
	// for testing
	actors_.push_back(new Carnivore(950 + rand() % 100));
	actors_.push_back(new Herbivore(950 + rand() % 100));
	actors_.push_back(new Herbivore(950 + rand() % 100));
	actors_.push_back(new Plant(rand() % 100));

	/*
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Plant(rand() % 100));
	}
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Carnivore(950 + rand() % 100));
	}
	while (rand() % 100 < chance)
	{
		actors_.push_back(new Herbivore(950 + rand() % 100));
	}
	*/
}

void Area::printAllActors()
{
	// c++11 for loop
	for (auto &a : actors_)
	{
		a->show();
	}
}

void Area::act()
{
	// create an iterator that points to the end of the vector
	auto end = actors_.end();

	// set hasEaten and hasMoved to false for all animals
	std::for_each(actors_.begin(), end, [](Actor* a)
	{
		if (myHelper::IsType<Animal, Actor>(a))
		{
			static_cast<Animal*>(a)->setHasEaten(false);
			static_cast<Animal*>(a)->setHasMoved(false);
		}
	});

	// loop through the vector
	for (auto it = actors_.begin(); it != end; it++)
	{
		if (myHelper::IsType<Carnivore, Actor>(*it))
		{
			// see if there are any herbivores in the vector
			auto herb = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				return myHelper::IsType<Herbivore, Actor>(a);
			});

			if (herb == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Carnivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
				}			
			}
			else
			{
				// erase the herbivore from the vector
				herb = actors_.erase(herb);
				// update hunger and hasEaten
				static_cast<Carnivore*>(*it)->eat();
				// update iterators
				end = actors_.end();
				it += (it > herb ? 1 : 0);
			}
		}
		else if (myHelper::IsType<Herbivore, Actor>(*it))
		{
			// see if there are any plants in the vector
			auto plant = std::find_if(actors_.begin(), actors_.end(), [](Actor *a)
			{
				return myHelper::IsType<Plant, Actor>(a);
			});

			if (plant == actors_.end())
			{
				// count hungerBar up, and erase if it hits max
				if (static_cast<Herbivore*>(*it)->increaseHunger())
				{
					// erase the carnivore from the vector
					it = actors_.erase(it);
				}
			}
			else
			{
				// erase the herbivore from the vector
				plant = actors_.erase(plant);
				// update hunger and hasEaten
				static_cast<Herbivore*>(*it)->eat();
				// update iterators
				end = actors_.end();
				it += (it > plant ? 1 : 0);
			}
		}
		else if (myHelper::IsType<Plant, Actor>(*it))
		{
			int dummy = 1;
		}
	}
}

std::vector<Actor*> *Area::getActors()
{
	return &actors_;
}