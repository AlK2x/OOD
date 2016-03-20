#include "stdafx.h"
#include "Display.h"

void CDisplay::Update(SWeatherInfo const & data)
{
	if (data.type == WeatherDataType::INDOOR)
	{
		m_inData = data;
	}
	else if (data.type == WeatherDataType::OUTDOOR)
	{
		m_outData = data;
	}

	std::cout << "In: " << std::endl;
	DisplayData(m_inData);
	std::cout << "Out: " << std::endl;
	DisplayData(m_outData);

	std::cout << "----------------" << std::endl;
}

void CDisplay::DisplayData(SWeatherInfo const & data) const
{
	for (auto & info : data.sensorData)
	{
		std::cout << "Current " << SensorInfo::getDescription(info.first) << " " << info.second << std::endl;
	}
}
