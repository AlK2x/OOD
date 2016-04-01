#include "stdafx.h"
#include "StatsDisplay.h"
#include "WeatherDataType.h"
#include "WeatherInfo.h"

void CStatsDisplay::Update(IObservable<SWeatherInfo> const& subject)
{
	const CWeatherData * subj = dynamic_cast<const CWeatherData*>(&subject);
	if (subj == NULL)
	{
		return;
	}

	m_temp.Update(subj->GetTemperature());
	m_pressure.Update(subj->GetPressure());
	m_humidity.Update(subj->GetHumidity());
	m_windSpeed.Update(subj->GetWindSpeed());
	m_windDirection.Update(subj->GetWindSpeed(), subj->GetWindDirection());

	switch (subj->GetLocation())
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
