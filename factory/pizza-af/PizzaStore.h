#pragma once
#include "Pizza.h"


class CPizzaStore
{
public:
	std::unique_ptr<CPizza> OrderPizza(const std::string& type)
	{
		auto pizza = CreatePizza(type);

		std::cout << "--- Making a " << pizza->GetName() + " ---" << std::endl;

		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();

		return pizza;
	}

	virtual ~CPizzaStore() = default;
protected:
	virtual std::unique_ptr<CPizza> CreatePizza(const std::string& type) = 0;
};

class CNYPizzaStore : public CPizzaStore
{
protected:

	virtual std::unique_ptr<CPizza> CreatePizza(const std::string& type) override
	{
		using namespace std;
		unique_ptr<CPizza> pizza;
		auto ingredientFactory = make_unique<CNyPizzaIngredientFactory>();
		if (type == "cheese")
		{
			pizza = make_unique<CCheesePizza>(move(ingredientFactory));
			pizza->SetName("New York Style Cheese Pizza");
		}
		else if (type == "clam")
		{
			pizza = make_unique<CClamPizza>(move(ingredientFactory));
			pizza->SetName("New York Style Cheese Pizza");
		}
		else
		{
			/* ������ ���� ����� */
		}
		return pizza;
	}
};

class CChicagoPizzaStore : public CPizzaStore
{
protected:

	virtual std::unique_ptr<CPizza> CreatePizza(const std::string& type) override
	{
		using namespace std;
		unique_ptr<CPizza> pizza;
		auto ingredientFactory = make_unique<CChicagoPizzaIngredientFactory>();
		if (type == "cheese")
		{
			pizza = make_unique<CCheesePizza>(move(ingredientFactory));
			pizza->SetName("Chicagok Style Cheese Pizza");
		}
		else if (type == "clam")
		{
			pizza = make_unique<CClamPizza>(move(ingredientFactory));
			pizza->SetName("Chicago Style Cheese Pizza");
		}
		else
		{
			/* ������ ���� ����� */
		}
		return pizza;
	}
};

class CAshotsPizzaStore : public CPizzaStore
{
protected:
	std::unique_ptr<CPizza> CreatePizza(const std::string& /*type*/) override
	{
		auto pizza = std::make_unique<CLavash>(&ThickCrustDoughtFactory);
		pizza->SetName("Lavash");
		return std::move(pizza);
	}
};