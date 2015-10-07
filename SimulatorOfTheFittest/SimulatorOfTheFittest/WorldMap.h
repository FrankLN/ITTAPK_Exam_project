#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <iostream>

template<typename T, size_t X, size_t Y = X>
class WorldMap
{
public:
	WorldMap<T, X, Y>(){}

	void printAll()
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				std::cout << "data_[" << i << "][" << j << "] = " << data_[i][j] << std::endl;
			}
		}
	}

	T getDataItem(int x, int y)
	{
		return data_[x][y];
	}
private:
	T data_[X][Y];
};

#endif