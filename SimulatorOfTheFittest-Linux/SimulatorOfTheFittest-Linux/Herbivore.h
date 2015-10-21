#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <iostream>
#include "Animal.h"

class Herbivore : public Animal
{
public:
	Herbivore();
	~Herbivore();

	void show();
	std::string showToString();
};

#endif