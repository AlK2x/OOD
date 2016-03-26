#include "stdafx.h"
#include "Display.h"

void CDisplay::Update(SWeatherInfo const & data)
{
	std::cout << "Tempearure: " << data.temperature << std::endl;
	std::cout << "Pressure  : " << data.pressure << std::endl;
	std::cout << "Humidity  : " << data.humidity << std::endl;

	std::cout << "----------------" << std::endl;
}
