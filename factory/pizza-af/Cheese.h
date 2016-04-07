#pragma once
#include <string>

class ICheese
{
public:
	virtual std::string ToString()const = 0;

	virtual ~ICheese() = default;
};

class CReggianoCheese : public ICheese
{
	std::string ToString() const override
	{
		return "Reggiano Cheese";
	}

};

class CMazarellaCheese : public ICheese
{
	std::string ToString() const override
	{
		return "Mazarellls Cheese";
	}
};