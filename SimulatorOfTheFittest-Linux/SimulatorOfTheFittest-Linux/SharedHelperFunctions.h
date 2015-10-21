#ifndef SHARED_HELPER_FUNCTIONS_H
#define SHARED_HELPER_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>

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
			auto oldest = actors.begin();
			std::string logstr;
			logstr.append("Actors left:");

			for (auto it = actors.begin(); it != actors.end(); it++)
			{
				logstr.append("\n\n");
				logstr.append((*it)->showToString());
				if ((*it)->getAge() > (*oldest)->getAge())
					oldest = it;
			}

			logstr.append("\n\n");
			logstr.append("Total number of actors: ");
			logstr.append(std::to_string(actors.size()));
			logstr.append("\n");
			logstr.append("Oldest actor: \n");
			logstr.append((*oldest)->showToString());


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

#endif