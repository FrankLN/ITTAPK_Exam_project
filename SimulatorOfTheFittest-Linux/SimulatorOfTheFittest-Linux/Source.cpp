#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include <exception>
#include <iostream>
#include <vector>
#include "WorldMap.h"
#include "Area.h"
#include "Simulation.cpp"
#include <boost/smart_ptr.hpp>
#include <boost/signals2.hpp>
//#include "SharedHelperFunctions.h"

void start();

void setupMap(const int&, const int&);

int main()
{
	WorldMapHolder* wm;
	Simulator mySimulator;
	int x, y;

	// State: SimulatorSetup
	mySimulator.initiate();
	setupMap(x, y);






	// State: Running
	mySimulator.process_event(EvStart());

	while (!myHelpers::kbhit<Actor>())
	{
		std::cout << "Waiting for interrupt" << std::endl;
	}
	// State: Pause
	mySimulator.process_event(EvPauseRun());



	return 0;
}

void setupMap(const int& x, const int& y)
{
	std::string input;
	std::cout << "Please insert size of map: ";
	std::cin >> input;

	if (input.find_first_not_of("0123456789 "))
		input = "0";

	std::vector<std::string> elem;
	std::split(input, " ", elem);

	switch (elem.size())
	{
	case 1:
		*x = std::stoi(input);
		*y = *x;
		break;
	case 2:
		*x = std::stoi(elem[0]);
		*y = std::stoi(elem[1]);
		break;
	default:
		setupMap(x, y);
	}
}

//void start()
//{
//	Simulator mySimulator;
//	bool finish = false;
//	bool quit = false;
//	bool reset = false;
//
//
//
//	while (!finish && !quit)
//	{
//		finish = true;
//		for(int i = 0; i < 20 ; i++) std::cout << std::endl;
//		std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
//		std::cout << "<=----------------Main menu--------------=>" << std::endl;
//		std::cout << "<=-----------------1. Start--------------=>" << std::endl;
//		std::cout << "<=-----------------2. Quit---------------=>" << std::endl;
//		std::cout << "<=--Select option: ";
//
//
//		int option;
//		std::cin >> option;
//		std::string str;
//		std::getline(std::cin, str);
//
//		switch (option)
//		{
//		case 1:
//			for (int i = 0; i < 20; i++) std::cout << std::endl;
//			mySimulator.initiate();
//
//			for (int i = 0; i < 20; i++) std::cout << std::endl;
//			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
//			mySimulator.process_event(EvStart());
//			break;
//		case 2:
//			quit = true;
//			break;
//		default:
//			finish = false;
//		}
//	}
//
//	while (!quit && !reset)
//	{
//		std::cout << "<=-----------------1. Quit---------------=>" << std::endl;
//		std::cout << "<=-----------------2. Pause/Resume-------=>" << std::endl;
//		std::cout << "<=-----------------3. Reset--------------=>" << std::endl;
//		std::cout << "<=-----------------4. Toggle log---------=>" << std::endl;
//		std::cout << "<=--Select option: ";
//
//		int option;
//		std::cin >> option;
//		std::string str;
//		std::getline(std::cin, str);
//
//		switch (option)
//		{
//		case 1:
//			quit = true;
//			break;
//		case 2:
//			for (int i = 0; i < 20; i++) std::cout << std::endl;
//			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
//			mySimulator.process_event(EvPauseRun());
//			break;
//		case 3:
//			reset = true;
//			break;
//		case 4:
//			for (int i = 0; i < 20; i++) std::cout << std::endl;
//			std::cout << "<=--------Simulator of the fittest-------=>" << std::endl;
//			mySimulator.process_event(EvLogOnOff());
//			break;
//
//		}
//	}
//
//
//	if (reset)
//		start();
//}
