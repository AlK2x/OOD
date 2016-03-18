#include "stdafx.h"
#include "StatsDisplay.h"

CStatsDisplay::CStatsDisplay()
{
	for (auto & sensorInfo : SENSOR_INFOS)
	{
		m_minSensorValue[sensorInfo.type] = std::numeric_limits<double>::infinity();
		m_maxSensorValue[sensorInfo.type] = -std::numeric_limits<double>::infinity();
		m_accSensorValue[sensorInfo.type] = 0;
	}
}

void CStatsDisplay::Update(SWeatherInfo const & data)
{
	for (auto & info : data.sensorData)
	{
		m_maxSensorValue[info.first] = std::max(m_maxSensorValue[info.first], info.second);
		m_minSensorValue[info.first] = std::min(m_minSensorValue[info.first], info.second);
		m_accSensorValue[info.first] += info.second;

		std::cout << "Max " << SensorInfo::getDescription(info.first) << " " << m_maxSensorValue[info.first] << std::endl;
		std::cout << "Min " << SensorInfo::getDescription(info.first) << " " << m_minSensorValue[info.first] << std::endl;
		std::cout << "Average " << SensorInfo::getDescription(info.first) << " " << (m_accSensorValue[info.first] / m_countAcc) << std::endl;
	}
	++m_countAcc;

	std::cout << "----------------" << std::endl;
}
