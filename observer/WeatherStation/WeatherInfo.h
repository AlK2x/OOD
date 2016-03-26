#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherDataType.h"

struct SWeatherInfo
{
	double temperature;
	double pressure;
	double humidity;
};

enum class Location
{
	Indoor,
	Outdoor
};