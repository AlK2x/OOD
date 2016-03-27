#include "stdafx.h"
#include "StatsDisplay.h"
#include "WeatherDataType.h"
#include "WeatherInfo.h"

void CStatsDisplay::Update(SWeatherInfo const & data)
{
	m_temp.Update(data.temperature);
	m_pressure.Update(data.pressure);
	m_humidity.Update(data.humidity);

	std::cout << "\\\\\\\\\\\\\\\\\\  Print statsistic //////////////////" << std::endl;
	std::cout << "Temperature: " << std::endl;
	DisplayData(m_temp);
	std::cout << "Pressure   : " << std::endl;
	DisplayData(m_pressure);
	std::cout << "Humidity   : " << std::endl;
	DisplayData(m_humidity);

	std::cout << "----------------" << std::endl;
}

void CStatsDisplay::DisplayData(CSensorStatistic const & stats) const
{
	std::cout << "    Maximum: " << stats.getMax() << std::endl;
	std::cout << "    Minimum: " << stats.getMin() << std::endl;
	std::cout << "    Average: " << stats.GetAverage() << std::endl;
}
