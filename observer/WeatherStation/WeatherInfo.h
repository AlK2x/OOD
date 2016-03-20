#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherDataType.h"

struct SWeatherInfo
{
	std::map<SensorType, double> sensorData;
	WeatherDataType type;
};

