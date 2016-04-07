#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

int main()
{
	//CNYPizzaStore store;
	//auto pizze = store.OrderPizza("cheese");
	//auto mid = store.OrderPizza("clam");
	//std::cout << pizze->ToString();
	//std::cout << mid->ToString();

	CAshotsPizzaStore uAshota;
	auto lavash = uAshota.OrderPizza("It doesn't matter. Only lavash is produced");
	std::cout << lavash->ToString();

	return 0;
}