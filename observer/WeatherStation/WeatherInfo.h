#pragma once
#include "stdafx.h"
#include "SensorType.h"

struct SWeatherInfo
{
	std::map<SensorType, double> sensorData;
};

