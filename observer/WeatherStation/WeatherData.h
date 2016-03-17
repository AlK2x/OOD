#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include "Observer.h"
#include "SensorType.h"

using namespace std;

struct SWeatherInfo
{
	std::map<SensorType, double> sensorData;
};

class CDisplay: public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override
	{
		for (auto & info : data.sensorData)
		{
			std:cout << "Current " << SensorInfo::getDescription(info.first)  << " " << info.second << std::endl;
		}

		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay()
	{
		for (auto & sensorInfo : SENSOR_INFOS)
		{
			m_minSensorValue[sensorInfo.type] = std::numeric_limits<double>::infinity();
			m_maxSensorValue[sensorInfo.type] = -std::numeric_limits<double>::infinity();
			m_accSensorValue[sensorInfo.type] = 0;
		}
	}

	void Update(SWeatherInfo const& data) override
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
private:
	std::map<SensorType, double> m_minSensorValue;
	std::map<SensorType, double> m_maxSensorValue;
	std::map<SensorType, double> m_accSensorValue;

	unsigned m_countAcc = 0;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.sensorData[SensorType::TEMPERATURE] = GetTemperature();
		info.sensorData[SensorType::HUMIDITY] = GetHumidity();
		info.sensorData[SensorType::PRESSURE] = GetPressure();
		
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;	
	double m_pressure = 760.0;	
};
