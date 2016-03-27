#include "stdafx.h"
#include "WeatherData.h"
#include "WeatherDataType.h"

// Температура в градусах Цельсия

double CWeatherData::GetTemperature() const
{
	return m_temperature;
}

// Относительная влажность (0...100)
double CWeatherData::GetHumidity() const
{
	return m_humidity;
}

// Атмосферное давление (в мм.рт.ст)
double CWeatherData::GetPressure() const
{
	return m_pressure;
}

void CWeatherData::SetWeatherDataType(WeatherDataType type)
{
	m_type = type;
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temp, double humidity, double pressure)
{
	m_humidity = humidity;
	m_temperature = temp;
	m_pressure = pressure;

	MeasurementsChanged();
}

SWeatherInfo CWeatherData::GetChangedData() const
{
	SWeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();

	return info;
}
