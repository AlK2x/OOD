#include "stdafx.h"
#include "WeatherData.h"
#include "WeatherDataType.h"

double CWeatherData::GetTemperature() const
{
	return m_temperature;
}

double CWeatherData::GetHumidity() const
{
	return m_humidity;
}

double CWeatherData::GetPressure() const
{
	return m_pressure;
}

double CWeatherData::GetWindSpeed() const
{
	return m_windSpeed;
}

double CWeatherData::GetWindDirection() const
{
	return m_windDirection;
}

Location CWeatherData::GetLocation() const
{
	return m_loc;
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temp, double humidity, double pressure, double windSpeed, double windDirection)
{
	m_humidity = humidity;
	m_temperature = temp;
	m_pressure = pressure;
	m_windSpeed = windSpeed;
	m_windDirection = windDirection;

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
