#pragma once
#include "SensorType.h"
#include "WeatherData.h"
#include "WeatherInfo.h"
#include "IObserver.h"
#include "WindSensorStatistic.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(CWeatherData * subject) : m_subejct(subject) {}

	void Update(IObservable<SWeatherInfo> const& subject) override;
private:
	void DisplayData(CSensorStatistic const & stats) const;

	CSensorStatistic m_temp;
	CSensorStatistic m_pressure;
	CSensorStatistic m_humidity;
	CSensorStatistic m_windSpeed;
	CWindSensorStatistic m_windDirection;

	CWeatherData* m_subejct;
};
