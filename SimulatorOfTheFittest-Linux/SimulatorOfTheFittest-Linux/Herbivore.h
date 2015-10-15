#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <iostream>
#include <typeinfo>

#include "Animal.h"

class Herbivore : public Animal
{
public:
	Herbivore(float);
	void show();
};

#endif