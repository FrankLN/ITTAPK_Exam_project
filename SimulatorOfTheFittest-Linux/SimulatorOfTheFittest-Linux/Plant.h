#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <typeinfo>
#include "Actor.h"

class Plant : public Actor
{
public:
	Plant(float mass);
	~Plant();
	void show();
};

#endif