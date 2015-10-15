#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include <exception>
#include <iostream>
#include <vector>
#include "WorldMap.h"
#include "Area.h"
#include "Simulation.cpp"
#include "ActorTypeList.h"
#include <boost/smart_ptr.hpp>

int main()
{
	WorldMap<Area, 1> wm = WorldMap<Area, 1>();

	Simulator mySimulator;
	mySimulator.initiate();
	
	return 0;
}