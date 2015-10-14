#include <random>

#include "Area.h"

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
		actors_.push_back(new Plant(rand() % 100 / 100));
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

void Area::act()
{	
	printAllActors();
	
	size_t s = actors_.size();
	
	for(int i=0; i<s; i++)
	{
		if (actors_[i]->getName() == "Herbivore")
		{
			for (int j = 0; j < s; j++)
			{
				if (actors_[j]->getName() == "Carnivore")
				{
					Carnivore* temp = dynamic_cast<Carnivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat(actors_[i]);
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
		else if (actors_[i]->getName() == "Plant")
		{
			for(int j=i; j<s; j++)
			{
				if (actors_[j]->getName() == "Herbivore")
				{
					Herbivore* temp = dynamic_cast<Herbivore*>(actors_[j]);
					if (!temp->hasEaten())
					{
						temp->eat(actors_[i]);
						actors_.erase(actors_.begin() + i);
						s = actors_.size();
						i--;
						break;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < s; i++)
	{
		if (actors_[i]->getName() != "Plant")
		{
			dynamic_cast<Animal*>(actors_[i])->setHasEaten(false);
		}
	}
	
	printAllActors();
}
