#pragma once
#include "stdafx.h"
#include "Observable.h"
#include "SensorType.h"
#include "WeatherInfo.h"
#include "SensorStatistic.h"

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	CWeatherData(Location location)
		:m_loc(location) {}

	// Температура в градусах Цельсия
	double GetTemperature()const;
	// Относительная влажность (0...100)
	double GetHumidity()const;
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const;

	double GetWindSpeed()const;

	WindDirection GetWindDirection()const;

	Location GetLocation() const;

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure);
protected:
	SWeatherInfo GetChangedData()const override;
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
	double m_windSpeed = 0.0;
	WindDirection m_windDirection = WindDirection::Calm;

	Location m_loc;
};

