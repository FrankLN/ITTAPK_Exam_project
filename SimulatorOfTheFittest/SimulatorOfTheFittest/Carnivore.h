#ifndef CARNIVORE_H
#define CARNIVORE_H


#include "Animal.h"

class Carnivore : public Animal
{
public:
	Carnivore(float);
	void show();
};

#endif