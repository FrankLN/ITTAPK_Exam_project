#ifndef ACTOR_H
#define	ACTOR_H

#include <string>

class Actor
{
protected:
	int age_;
public:
	virtual ~Actor() = default;
	virtual void show() = 0;
	virtual std::string showToString() = 0;
	virtual void incAge()
	{
		age_++;
	}
	virtual int getAge()
	{
		return age_;
	}
};

#endif