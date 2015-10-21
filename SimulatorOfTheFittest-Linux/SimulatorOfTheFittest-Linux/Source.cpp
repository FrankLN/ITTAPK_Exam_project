#include <iostream>
#include <vector>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <boost/signals2.hpp>

#include "Carnivore.h"
#include "Plant.h"
#include "Herbivore.h"
#include "WorldMap.h"
#include "Area.h"
#include "Simulation.cpp"
#include "SharedHelperFunctions.h"

void setupMap(int&, int&);
int getNumberOfRuns();
bool run(int&, int&, WorldMapHolder*);
int breakMenu();
void pauseMenu();
int setResultRender();

int main()
{
	boost::signals2::signal<void(std::vector<Actor*>)> sig1;
	WorldMapHolder* wm;
	Simulator mySimulator;
	int x, y;

	// State: SimulatorSetup
	mySimulator.initiate();
	setupMap(x, y);
	wm = GetWorldMap::getWorldMap(x, y);
	switch (setResultRender())
	{
	case 2:
		sig1.connect(ResultToConsole());
		break;
	case 3:
		sig1.connect(ResultToFile());
		break;
	case 4:
		sig1.connect(ResultToConsole());
		sig1.connect(ResultToFile());
		break;
	}

	// main part of program
	bool finish = false;
	while (!finish)
	{
		// State: Running
		mySimulator.process_event(EvStart());
		int n = getNumberOfRuns();
		int i = 0;

		bool canceled = false;
		while (!canceled && run(i, n, wm))
		{
			// State: Pause
			mySimulator.process_event(EvPauseRun());
			switch (breakMenu())
			{
			case 1:		// Continue
				// State: Running
				mySimulator.process_event(EvPauseRun());
				break;
			case 2:		// Cancel
				// State: Cancel
				mySimulator.process_event(EvCancel());
				canceled = true;
				break;
			}
		}

		if (!canceled)
		{
			// State: Finished
			mySimulator.process_event(EvSimulationFinished());
			sig1(wm->getAllActors());
		}
		finish = true;
	}

	delete wm;

	return 0;
}

void setupMap(int& x, int& y)
{
	std::string input;
	std::cout << "Please insert size of map: ";
	std::getline(std::cin, input);

	size_t last = input.find_last_of(" ");
	size_t first = input.find(" ");
	
	if (last == first && input != "" && input.find_first_not_of("0123456789 ") == std::string::npos)
	{
		if (first == std::string::npos)
		{
			int result = std::stoi(input);
			x = result;
			y = result;
		}
		else
		{
			x = std::stoi(input.substr(0, first));
			y = std::stoi(input.substr(first));
		}
	}
	else
	{
		std::cout << "*** ERROR: invalid input ***" << std::endl;
		setupMap(x, y);
	}
}

int getNumberOfRuns()
{
	std::cout << "Please insert number of runs requested: ";
	std::string input;
	std::cin >> input;
	
	if (!input.find_first_not_of("0123456789") || input == "")
	{
		std::cout << "Only input numbers!" << std::endl;
		return getNumberOfRuns();
	}

	int result = std::stoi(input);
	return result;
}

// Funktionen kbhit(void) er fundet her http://stackoverflow.com/a/7105749
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

bool run(int& i, int& n, WorldMapHolder* wmP)
{
	std::string tmp;
	while (kbhit())
		std::getline(std::cin, tmp);
	while(i < n && !kbhit())
	{
		wmP->actAll();
		i++;
		std::cout << i << std::endl;
	}
	if (i < n)
	{
		return true;
	}
	return false;
}

int breakMenu()
{
	std::cout << "1. Continue" << std::endl << "2. Cancel" << std::endl << "Please insert a valid option: ";
	std::string input;
	std::cin >> input;

	if (!input.find_first_not_of("0123456789") || input == "")
	{
		std::cout << "Only input numbers!" << std::endl;
		return breakMenu();
	}

	int result = std::stoi(input);
	if (result != 1 && result != 2)
	{
		std::cout << "Not a valid option" << std::endl;
		return breakMenu();
	}
	return result;
}

int setResultRender()
{
	std::cout << "1. No render" << std::endl <<
		"2. Console render" << std::endl <<
		"3. Logfile render" << std::endl <<
		"4. Both render" << std::endl <<
		"Please insert a valid option: ";

	std::string input;
	std::cin >> input;

	if (!input.find_first_not_of("0123456789") || input == "")
	{
		std::cout << "Only input numbers!" << std::endl;
		return setResultRender();
	}

	int result = std::stoi(input);
	if (result != 1 && result != 2 && result != 3 && result != 4)
	{
		std::cout << "Not a valid option" << std::endl;
		return setResultRender();
	}
	return result;
}