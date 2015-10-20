#ifndef SHARED_HELPER_FUNCTIONS_H
#define SHARED_HELPER_FUNCTIONS_H

#include <iostream>
#include <vector>

#include <boost/preprocessor.hpp>

struct ResultToConsole
{
	void operator()(std::vector<Actor*> actors) const { actors[0]->show(); }
};

struct ResultToFile
{
	void operator()(std::vector<Actor*> actors) const 
	{ 
		actors[0]->show(); 
	}
};


namespace myHelper
{	
	template<typename DstType, typename SrcType>
	bool IsType(SrcType* src)
	{
		return dynamic_cast<DstType*>(src) != 0;
	}
	
	template<typename T>
	void Split(std::string str, T &dst, std::string delim)
	{
		std::vector<std::string> result;
		
		std::cout << str << std::endl;
		
		
		dst = result;
	}

}

#endif