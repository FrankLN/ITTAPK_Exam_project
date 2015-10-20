#include <random>
#include <boost/smart_ptr.hpp>

#include "Area.h"
#include "SharedHelperFunctions.h"

#define chance 10

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
	/*for (auto it = actors_.begin(); it != actors_.end(); it++)
	{
		delete (*it);
	}

	actors_.clear();*/
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
	
}

void Area::printAllActors()
{
	for (auto &a : actors_)
	{
		a->show();
	}
}

std::vector<Actor*> Area::getAllActors()
{
	std::vector<Actor*> result = std::vector<Actor*>();
	for (auto it = actors_.begin(); it != actors_.end(); it++)
	{
		result.push_back(*it);
	}
	return result;
}

void Area::act()
{
	// print all actors
	/*printAllActors();
	std::cout << "------------------------------------------" << std::endl;*/

	// set hasEaten and hasMoved to false for all animals
	std::for_each(actors_.begin(), actors_.end(), [](Actor* a)
	{
		a->incAge();
		if (myHelper::IsType<Animal, Actor>(a))
		{
			static_cast<Animal*>(a)->setHasEaten(false);
			static_cast<Animal*>(a)->setHasMoved(false);
		}
	});

	// loop through the vector
	for (auto it = actors_.begin(); it != actors_.end(); )
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
				else
				{
					// increment iterator
					it++;
				}
			}
			else
			{
				// update hunger and hasEaten
				static_cast<Carnivore*>(*it)->eat();
				// erase the herbivore from the vector
				herb = actors_.erase(herb);
				// update iterator
				if (it < herb && it != actors_.end())
				{
					it++;
				}
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
				else
				{
					// increment iterator
					it++;
				}
			}
			else
			{
				// update hunger and hasEaten
				static_cast<Herbivore*>(*it)->eat();
				// erase the herbivore from the vector
				plant = actors_.erase(plant);
				// update iterator
				if (it < plant && it != actors_.end())
				{
					it++;
				}
			}
		}
		else if (myHelper::IsType<Plant, Actor>(*it))
		{
			// increment iterator
			it++;
		}
	}
	
	// generate new actors and print all actors
	/*printAllActors();
	std::cout << "------------------------------------------" << std::endl;*/

}

std::vector<Actor*> *Area::getActors()
{
	return &actors_;
}