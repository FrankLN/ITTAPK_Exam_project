#include <random>
#include <boost/smart_ptr.hpp>

#include "Area.h"
#include "SharedHelperFunctions.h"

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
	for (int i = 0; i < actors_.size(); i++)
	{
		delete actors_[i];
	}
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
	while (rand() % 100 < 70)
	{
		actors_.push_back(new Plant(rand() % 100));
	}
	while (rand() % 100 < 70)
	{
		actors_.push_back(new Carnivore(950 + rand() % 100));
	}
	while (rand() % 100 < 70)
	{
		actors_.push_back(new Herbivore(950 + rand() % 100));
	}
}

void Area::printAllActors()
{
	for (int i = 0; i < actors_.size(); i++)
	{
		actors_[i]->show();
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
	//std::cout << "<<<Before act>>>" << std::endl;
	//printAllActors();
	
	size_t s = actors_.size();
	
	for(int i=0; i<s; i++)
	{
		if(myHelper::IsType<Herbivore, Actor>(actors_[i]))
		{
			for (int j = 0; j < s; j++)
			{
				if (myHelper::IsType<Carnivore, Actor>(actors_[j]))
				{
					Carnivore* temp = dynamic_cast<Carnivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat<Herbivore>(actors_[i]);
						delete actors_[i];
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
		else if (myHelper::IsType<Plant, Actor>(actors_[i]))
		{
			for(int j=i; j<s; j++)
			{
				if (myHelper::IsType<Herbivore, Actor>(actors_[j]))
				{
					Herbivore* temp = dynamic_cast<Herbivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat<Plant>(actors_[i]);
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
	}


	
	/*for (int i = 0; i < s; i++)
	{
		actors_[i]->incAge();
		if (!myHelper::IsType<Plant, Actor>(actors_[i]))
		{
			Animal* temp  = dynamic_cast<Animal*>(actors_[i]);
			temp->setHasEaten(false);
			if (temp->increaseHunger())
			{
				actors_.erase(actors_.begin() + i);
				s = actors_.size();
				i--;
			}
				
		}
	}*/

	int i = 0;
	std::for_each(actors_.begin(), actors_.end(), [this, &i](Actor* actor)
	{
		actor->incAge();
		if (!myHelper::IsType<Plant, Actor>(actor))
		{
			Animal* temp = dynamic_cast<Animal*>(actor);
			temp->setHasEaten(false);
			if (temp->increaseHunger())
			{
				actors_.erase(actors_.begin() + i);
			}
		}
		i++;
	});
	
	
	//std::cout << "<<<After act>>>" << std::endl;
	//printAllActors();
	
	
	//std::cout << "<<<New generates>>>" << std::endl;
	generateRandomActors();
	//printAllActors();
}
