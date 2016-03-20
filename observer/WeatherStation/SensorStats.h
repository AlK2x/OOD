#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherData.h"
#include "WeatherInfo.h"

class CSensorStats
{
public:
	CSensorStats();
	void UpdateStats(SWeatherInfo const & data);
	void DisplayStats(std::ostream & ist) const;
	bool isInitialized() const;

	~CSensorStats() = default;
private:
	std::map<SensorType, double> m_minSensorValue;
	std::map<SensorType, double> m_maxSensorValue;
	std::map<SensorType, double> m_accSensorValue;

	unsigned m_countAcc = 0;
	bool m_initialized;
};

