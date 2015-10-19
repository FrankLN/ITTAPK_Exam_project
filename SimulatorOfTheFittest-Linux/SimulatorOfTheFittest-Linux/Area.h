#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>

#include "Actor.h"
#include "Plant.h"
#include "Carnivore.h"
#include "Herbivore.h"

class Area
{
private:
	std::string name_;
	int seed_;
	std::vector<Actor*> actors_;
public:
	Area();
	~Area();

	std::string getName() const;
	int getSeed() const;
	int getRandomNumber() const;
	void generateRandomActors();
	void printAllActors();
	void act();
	void move();
	std::vector<Actor*> *getActors();
};

inline std::ostream & operator<<(std::ostream & Str, Area const & v) {
	// print something from v to str, e.g: Str << v.getX();
	Str << v.getName() << " with seed: " << v.getSeed();
	return Str;
}

#endif