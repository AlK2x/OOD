#include "stdafx.h"
#include "Display.h"

void CDisplay::Update(SWeatherInfo const & data)
{
	for (auto & info : data.sensorData)
	{
    	std::cout << "Current " << SensorInfo::getDescription(info.first) << " " << info.second << std::endl;
	}

	std::cout << "----------------" << std::endl;
}
