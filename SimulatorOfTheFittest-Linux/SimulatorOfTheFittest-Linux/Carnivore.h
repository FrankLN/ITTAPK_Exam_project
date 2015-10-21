#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <iostream>
#include <string>
#include "Animal.h"

class Carnivore : public Animal
{
public:
	Carnivore();
	~Carnivore();

	void show();
	std::string showToString();
};

#endif