#pragma once
#include "IObserver.h"
#include "WeatherInfo.h"
#include "WeatherData.h"

class CDisplay : public IObserver<SWeatherInfo>
{
public:
	CDisplay(CWeatherData * subject) : m_subject(subject) {}

	void Update(IObservable<SWeatherInfo> const& subject) override;
private:
	CWeatherData* m_subject;
};
