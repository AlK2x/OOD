#pragma once

enum class SensorType
{
	Temperature,
	Humidity,
	Pressure
};

struct SensorInfo
{
	SensorType st;
	const char * info;
};

static const SensorInfo SENSOR_INFO[] = 
{
	{SensorType::Temperature, "Temperature"},
	{SensorType::Humidity, "Humidity"},
	{SensorType::Pressure, "Pressure"}
};