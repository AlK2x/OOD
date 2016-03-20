#include "stdafx.h"
#include "SensorStats.h"


CSensorStats::CSensorStats()
	: m_initialized(false)
{
	for (auto & sensorInfo : SENSOR_INFOS)
	{
		m_minSensorValue[sensorInfo.type] = std::numeric_limits<double>::infinity();
		m_maxSensorValue[sensorInfo.type] = -std::numeric_limits<double>::infinity();
		m_accSensorValue[sensorInfo.type] = 0;
	}
}

void CSensorStats::UpdateStats(SWeatherInfo const & data)
{
	m_initialized = true;
	for (auto & info : data.sensorData)
	{
		m_maxSensorValue[info.first] = std::max(m_maxSensorValue[info.first], info.second);
		m_minSensorValue[info.first] = std::min(m_minSensorValue[info.first], info.second);
		m_accSensorValue[info.first] += info.second;
	}
	++m_countAcc;
}

void CSensorStats::DisplayStats(std::ostream & ost) const
{
	for (auto & info : SENSOR_INFOS)
	{
		ost << "Max " << SensorInfo::getDescription(info.type) << " " << m_maxSensorValue.at(info.type) << std::endl;
		ost << "Min " << SensorInfo::getDescription(info.type) << " " << m_minSensorValue.at(info.type) << std::endl;
		ost << "Average " << SensorInfo::getDescription(info.type) << " " << (m_accSensorValue.at(info.type) / m_countAcc) << std::endl;
	}
}

bool CSensorStats::isInitialized() const
{
	return m_initialized;
}
