#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <iostream>
#include <typeinfo>
#include <vector>
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