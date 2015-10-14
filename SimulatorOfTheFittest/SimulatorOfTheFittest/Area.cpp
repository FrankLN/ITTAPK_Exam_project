#include "Area.h"

Area::Area()
{
	GUID gidReference;
	HRESULT hCreateGuid = CoCreateGuid(&gidReference);

	seed_ = gidReference.Data1;

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
	int i = 0;
	for each (Actor* actor in actors_)
	{
		if (actor->getName() == "Plant")
		{
			for each (Actor* isHerbivore in actors_)
			{
				if (isHerbivore->getName() == "Herbivore")
				{
					Herbivore* temp = dynamic_cast<Herbivore*>(isHerbivore);
					if (!temp->hasEaten())
					{
						temp->eat(actor);
						break;
					}
				}
			}
		}
		i++;
	}
}
