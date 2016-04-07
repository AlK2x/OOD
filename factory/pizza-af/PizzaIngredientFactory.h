#pragma once
#include "Clams.h"
#include "Dough.h"
#include "Cheese.h"
#include "Veggies.h"
#include "Pepperoni.h"
#include "Sauce.h"
#include <memory>
#include <vector>
#include <functional>

typedef std::function<std::unique_ptr<IDough>()> DoughFactory;

std::unique_ptr<IDough> ThickCrustDoughtFactory()
{
	return std::make_unique<CThinCrustDough>();
}

class IPizzaIngredientFactory
{
public:
	virtual std::unique_ptr<IDough> CreateDough() = 0;
	virtual std::unique_ptr<ISauce> CreateSauce() = 0;
	virtual std::unique_ptr<ICheese> CreateCheese() = 0;
	virtual std::vector<std::unique_ptr<IVeggies>> CreateVeggies() = 0;
	virtual std::unique_ptr<IPepperoni> CreatePepperoni() = 0;
	virtual std::unique_ptr<IClams> CreateClam() = 0;

	virtual ~IPizzaIngredientFactory() = default;
};

class CNyPizzaIngredientFactory : public IPizzaIngredientFactory
{
	std::unique_ptr<IDough> CreateDough() override
	{
		return std::make_unique<CThinCrustDough>();
	}

	std::unique_ptr<ISauce> CreateSauce() override
	{
		return std::make_unique<CMarinaraSauce>();
	}

	std::unique_ptr<ICheese> CreateCheese() override
	{
		return std::make_unique<CReggianoCheese>();
	}

	std::vector<std::unique_ptr<IVeggies>> CreateVeggies() override
	{
		using namespace std;
		vector<unique_ptr<IVeggies>> veggies;
		veggies.push_back(unique_ptr<IVeggies>(new CGarlic()));
		veggies.push_back(unique_ptr<IVeggies>(new COnion()));
		veggies.push_back(unique_ptr<IVeggies>(new CMushroom()));
		veggies.push_back(unique_ptr<IVeggies>(new CRedPepper()));
		return veggies;
	}

	std::unique_ptr<IPepperoni> CreatePepperoni() override
	{
		return std::make_unique<CSlicedPepperoni>();
	}

	std::unique_ptr<IClams> CreateClam() override
	{
		return std::make_unique<CFreshClams>();
	}
};

class CChicagoPizzaIngredientFactory : public IPizzaIngredientFactory
{
	virtual std::unique_ptr<IDough> CreateDough() override
	{
		return std::make_unique<CThinCrustDough>();
	}
	virtual std::unique_ptr<ISauce> CreateSauce() override
	{
		return std::make_unique<CPlumTomatoSauce>();
	}
	virtual std::unique_ptr<ICheese> CreateCheese() override
	{
		return std::make_unique<CMazarellaCheese>();
	}
	virtual std::vector<std::unique_ptr<IVeggies>> CreateVeggies() override
	{
		using namespace std;
		vector<unique_ptr<IVeggies>> veggies;
		veggies.push_back(unique_ptr<IVeggies>(new CBlackOlives()));
		veggies.push_back(unique_ptr<IVeggies>(new CSpanich()));
		veggies.push_back(unique_ptr<IVeggies>(new CEggplant()));
		return veggies;
	}
	virtual std::unique_ptr<IPepperoni> CreatePepperoni() override
	{
		throw::std::logic_error("Not implemented");
	}
	virtual std::unique_ptr<IClams> CreateClam() override
	{
		return std::make_unique<CFrozenClams>();
	}
};