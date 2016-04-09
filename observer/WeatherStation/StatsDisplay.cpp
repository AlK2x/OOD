#include "stdafx.h"
#include "StatsDisplay.h"
#include "WeatherDataType.h"
#include "WeatherInfo.h"

void CStatsDisplay::Update(IObservable<SWeatherInfo> const& subject)
{
	if (&subject != m_subejct)
	{
		return;
	}
	m_temp.Update(m_subejct->GetTemperature());
	m_pressure.Update(m_subejct->GetPressure());
	m_humidity.Update(m_subejct->GetHumidity());
	m_windSpeed.Update(m_subejct->GetWindSpeed());
	m_windDirection.Update(m_subejct->GetWindSpeed(), m_subejct->GetWindDirection());

	switch (m_subejct->GetLocation())
	{
	case Location::Indoor :
		std::cout << "INDOOR" << std::endl;
		break;
	default:
		std::cout << "OUTDOOR" << std::endl;
	}
	std::cout << "\\\\\\\\\\\\\\\\\\  Print statsistic //////////////////" << std::endl;
	std::cout << "Temperature   : " << std::endl;
	DisplayData(m_temp);
	std::cout << "Pressure      : " << std::endl;
	DisplayData(m_pressure);
	std::cout << "Humidity      : " << std::endl;
	DisplayData(m_humidity);
	std::cout << "Wind Speed    : " << std::endl;
	DisplayData(m_windSpeed);
	std::cout << "Wind Direction: " << std::endl;
	DisplayData(m_windDirection);


	std::cout << "----------------" << std::endl;
}

void CStatsDisplay::DisplayData(CSensorStatistic const & stats) const
{
	std::cout << "    Maximum: " << stats.GetMax() << std::endl;
	std::cout << "    Minimum: " << stats.GetMin() << std::endl;
	std::cout << "    Average: " << stats.GetAverage() << std::endl;
}
