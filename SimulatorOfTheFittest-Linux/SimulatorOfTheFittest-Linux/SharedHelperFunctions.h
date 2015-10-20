#ifndef SHARED_HELPER_FUNCTIONS_H
#define SHARED_HELPER_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include <boost/preprocessor.hpp>

struct ResultToConsole
{
	void operator()(std::vector<Actor*> actors) const
	{
		auto oldest = actors.begin();
		for (auto it = actors.begin(); it != actors.end(); it++)
		{
			(*it)->show();
			if ((*it)->getAge() > (*oldest)->getAge())
				oldest = it;
		}
		std::cout << "Total number of actors: " << actors.size() << std::endl;
		std::cout << "Oldest actor: " << std::endl;
		(*oldest)->show();
	}
};

struct ResultToFile
{
	void operator()(std::vector<Actor*> actors) const 
	{ 
		if (!actors.empty())
		{
			std::string logstr;
			logstr.append("Actors left:");

			for (auto it = actors.begin(); it != actors.end(); it++)
			{
				logstr.append("\n\n");
				logstr.append((*it)->showToString());
			}

			std::ofstream myfile;
			myfile.open("log.txt");
			myfile << logstr;
			myfile.close();
		}
	}
};


namespace myHelper
{	
	template<typename DstType, typename SrcType>
	bool IsType(SrcType* src)
	{
		return dynamic_cast<DstType*>(src) != 0;
	}
}

namespace myHelpers
{
	template<typename T>
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
}

#endif