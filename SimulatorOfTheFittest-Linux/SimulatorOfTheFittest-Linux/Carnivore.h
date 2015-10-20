#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

#include "Animal.h"

class Carnivore : public Animal
{
public:
	Carnivore(float);
	~Carnivore();

	void show();
	std::string showToString();
};

#endif