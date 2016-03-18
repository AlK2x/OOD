#pragma once
#include "../WeatherStation/Observable.h"

class CDummyObservable : public CObservable<int>
{
protected:
	int GetChangedData() const;
};

