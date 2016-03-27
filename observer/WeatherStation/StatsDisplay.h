#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherData.h"
#include "WeatherInfo.h"
#include "IObserver.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override;
private:
	void DisplayData(CSensorStatistic const & stats) const;

	CSensorStatistic m_temp;
	CSensorStatistic m_pressure;
	CSensorStatistic m_humidity;
};
