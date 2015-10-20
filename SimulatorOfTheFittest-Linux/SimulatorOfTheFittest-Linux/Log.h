#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <iostream>
#include <boost/signals2.hpp>

class Log
{
private:
	
public:
	void print() {
		std::cout << "Log.print()" << std::endl;
	}
};

#endif