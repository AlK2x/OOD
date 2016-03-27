#pragma once
#include "../WeatherStation/IObserver.h"

class CDummyObserver : public IObserver<int>
{
public:
	explicit CDummyObserver(unsigned number) : m_number(number) {}
	
	void Update(IObservable<int> const& subject) override;

private:
	unsigned m_number;
};

