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

struct SensorDescripion
{
	static const std::string GetDescription(SensorType type)
	{
		switch (type)
		{
		case SensorType::Temperature:
			return "Temperature";
			break;
		case SensorType::Humidity:
			return "Humididty";
			break;
		case SensorType::Pressure:
			return "Pressure";
			break;
		default:
			return "Unknown sensor";
		}
	}
};

class CDisplay: public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override
	{
		for (auto & info : data.sensorData)
		{
			std:cout << "Current " << SensorDescripion::GetDescription(info.first)  << " " << info.second << std::endl;
		}

		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override
	{
		for (auto & data : data.sensorData)
		{

		}

		//if (m_minTemperature > data.temperature)
		//{
		//	m_minTemperature = data.temperature;
		//}
		//if (m_maxTemperature < data.temperature)
		//{
		//	m_maxTemperature = data.temperature;
		//}
		//m_accTemperature += data.temperature;
		++m_countAcc;

		std::cout << "Max Temp " << m_maxTemperature << std::endl;
		std::cout << "Min Temp " << m_minTemperature << std::endl;
		std::cout << "Average Temp " << (m_accTemperature / m_countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}
private:
	std::map<SensorType, double> m_minTemp;

	double m_minTemperature = std::numeric_limits<double>::infinity();
	double m_maxTemperature = -std::numeric_limits<double>::infinity();
	double m_accTemperature = 0;
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
		return humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		humidity = humidity;
		m_temperature = temp;
		pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.sensorData[SensorType::Temperature] = GetTemperature();
		info.sensorData[SensorType::Humidity] = GetHumidity();
		info.sensorData[SensorType::Pressure] = GetPressure();
		
		//info.temperature = GetTemperature();
		//info.humidity = GetHumidity();
		//info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double humidity = 0.0;	
	double pressure = 760.0;	
};
