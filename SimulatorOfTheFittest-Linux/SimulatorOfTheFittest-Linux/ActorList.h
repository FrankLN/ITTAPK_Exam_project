#ifndef ACTOR_LIST_H
#define ACTOR_LIST_H

#include <iostream>
#include <algorithm>

template<typename T>
class ActorList
{
};

template<typename T>
class ActorList<T*>
{
public:
	ActorList()
	{
		size_ = 0;
		capacity_ = 0;
	}

	void add(T* t) {
		if (capacity_ <= size_)
		{
			T* newData = new T[capacity_ + 1];

			std::copy(t_, t_ + size, newData);
			std::swap(t_, newData);
			delete[] newData;

			capacity_++;
		}

		t_[size_] = t;
		size_++;
	}
private:
	size_t size_;
	size_t capacity_;
	T* t_;
};

#endif