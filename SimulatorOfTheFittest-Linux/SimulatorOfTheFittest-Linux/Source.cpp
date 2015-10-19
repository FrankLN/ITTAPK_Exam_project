#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include <exception>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "WorldMap.h"
#include "Area.h"
#include "Simulation.cpp"
#include "ActorTypeList.h"

int main()
{
	WorldMap<Area, 2> wm = WorldMap<Area, 2>();
	wm.printAll();
	wm.actAll();


	/*
	ActorTypeList<Plant, ActorTypeList<Herbivore, NullType>> aTL;

	std::cout << " " << std::endl;

	Simulator mySimulator;
	mySimulator.initiate();
	*/
	
	return 0;
}