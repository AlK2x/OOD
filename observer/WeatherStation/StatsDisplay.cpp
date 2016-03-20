#include "stdafx.h"
#include "StatsDisplay.h"
#include "WeatherDataType.h"

CStatsDisplay::CStatsDisplay()
{
}

void CStatsDisplay::Update(SWeatherInfo const & data)
{
	if (data.type == WeatherDataType::INDOOR)
	{
		m_inData.UpdateStats(data);
	}
	else if (data.type == WeatherDataType::OUTDOOR)
	{
		m_outData.UpdateStats(data);
	}

	if (m_inData.isInitialized())
	{
		std::cout << "In: " << std::endl;
		DisplayData(m_inData);
	}
	if (m_outData.isInitialized())
	{
		std::cout << "Out: " << std::endl;
		DisplayData(m_outData);
	}

	std::cout << "----------------" << std::endl;
}

void CStatsDisplay::DisplayData(CSensorStats const & stats) const
{
	stats.DisplayStats(std::cout);
}
