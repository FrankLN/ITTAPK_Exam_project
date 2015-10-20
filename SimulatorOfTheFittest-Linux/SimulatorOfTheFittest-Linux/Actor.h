#ifndef ACTOR_H
#define	ACTOR_H

#include <string>
#include <vector>

class Actor
{
protected:
	int age_;
public:
	virtual ~Actor(){};
	virtual void show() = 0;
	virtual std::string showToString() = 0;
	virtual void incAge()
	{
		age_++;
	}
};

#endif