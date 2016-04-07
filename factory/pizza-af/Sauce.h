#pragma once
#include <string>

class ISauce
{
public:
	virtual std::string ToString()const = 0;

	virtual ~ISauce() = default;
};

class CMarinaraSauce : public ISauce
{
	std::string ToString() const override
	{
		return "Marinara Sauce";
	}

};

class CPlumTomatoSauce : public ISauce
{
	// Inherited via ISauce
	virtual std::string ToString() const override
	{
		return "Plum Tomato";
	}
};