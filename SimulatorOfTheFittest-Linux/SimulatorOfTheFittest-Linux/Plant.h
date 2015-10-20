#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <typeinfo>
#include <boost/signals2.hpp>
#include "Actor.h"

class Plant : public Actor
{
public:
	Plant(float mass);
	~Plant();
	void show();
	std::string showToString();
	boost::signals2::signal<Actor* (Actor*)> Sig;
};

#endif