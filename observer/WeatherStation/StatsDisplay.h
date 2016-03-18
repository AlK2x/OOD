#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherData.h"
#include "WeatherInfo.h"
#include "IObserver.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay();
	void Update(SWeatherInfo const& data) override;

private:
	std::map<SensorType, double> m_minSensorValue;
	std::map<SensorType, double> m_maxSensorValue;
	std::map<SensorType, double> m_accSensorValue;

	unsigned m_countAcc = 0;
};
