#pragma once
#include "../WeatherStation/IObserver.h"

class CDummyObserver : public IObserver<int>
{
public:
	explicit CDummyObserver(unsigned number) : m_number(number) {}
	
	void Update(int const& data) override;

private:
	unsigned m_number;
};

