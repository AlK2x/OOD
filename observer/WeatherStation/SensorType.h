#pragma once
#include <vector>

enum class SensorType
{
	TEMPERATURE,
	HUMIDITY,
	PRESSURE
};

struct SensorData
{
	SensorType type;
	const char * description;
};

const static SensorData SENSOR_INFOS[] =
{
	{ SensorType::TEMPERATURE, "Temperature" },
	{ SensorType::HUMIDITY, "Humidity" },
	{ SensorType::PRESSURE, "Pressure" }
};

struct SensorInfo
{
	static const char * getDescription(SensorType type)
	{
		for (auto & sensorInfo : SENSOR_INFOS)
		{
			if (sensorInfo.type == type)
			{
				return sensorInfo.description;
			}
		}
		return "";
	}
};

