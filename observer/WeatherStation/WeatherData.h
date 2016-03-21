﻿#pragma once
#include "stdafx.h"
#include "Observable.h"
#include "SensorType.h"
#include "WeatherInfo.h"

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const;
	// Относительная влажность (0...100)
	double GetHumidity()const;
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const;

	void SetWeatherDataType(WeatherDataType type);

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure);
protected:
	SWeatherInfo GetChangedData()const override;
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;

	WeatherDataType m_type = WeatherDataType::OUTDOOR;
};
