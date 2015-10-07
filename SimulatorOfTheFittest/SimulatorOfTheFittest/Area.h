#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

#include <Objbase.h>



class Area
{
private:
	std::string name_;
	int seed_;
	std::vector<Actor*> actors_;
public:
	Area()
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

	std::string getName() const
	{
		return name_;
	}

	int getSeed() const
	{
		return seed_;
	}

	int getRandomNumber() const
	{
		return rand();
	}

	void generateRandomActors()
	{
		while (rand() % 100 < 5)
		{
			actors_.push_back(new Plant(rand()%100/100));
		}
		while (rand() % 100 < 5)
		{
			actors_.push_back(new Carnivore(950 + rand()%100));
		}
		while (rand() % 100 < 5)
		{
			actors_.push_back(new Herbivore(950 + rand() % 100));
		}
	}

	void printAllActors()
	{
		for (int i = 0; i < actors_.size(); i++)
		{
			actors_[i]->show();
		}
	}

	void act()
	{
		if (std::find(actors_.begin(), actors_.end(), new Plant(42)) != actors_.end())
		{

		}

	}

};

inline std::ostream & operator<<(std::ostream & Str, Area const & v) {
	// print something from v to str, e.g: Str << v.getX();
	Str << v.getName() << " with seed: " << v.getSeed();
	return Str;
}

#endif