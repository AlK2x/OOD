#pragma once
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

enum class WindDirection
{
	Calm,
	North,
	East,
	South,
	West
};