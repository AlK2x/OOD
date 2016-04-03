#pragma once
#include "Observable.h"
#include "IObserver.h"
#include "WeatherInfo.h"

class CBadWeatherData : public IObserver<SWeatherInfo>
{
public:
	CBadWeatherData(IObservable<SWeatherInfo> && wd);

	void Update(SWeatherInfo const & data);
private:
	IObservable<SWeatherInfo> & m_wd;
};
