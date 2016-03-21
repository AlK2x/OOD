#include "stdafx.h"
#include "WeatherData.h"
#include "WeatherDataType.h"

// ����������� � �������� �������

double CWeatherData::GetTemperature() const
{
	return m_temperature;
}

// ������������� ��������� (0...100)
double CWeatherData::GetHumidity() const
{
	return m_humidity;
}

// ����������� �������� (� ��.��.��)
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
	info.sensorData[SensorType::TEMPERATURE] = GetTemperature();
	info.sensorData[SensorType::HUMIDITY] = GetHumidity();
	info.sensorData[SensorType::PRESSURE] = GetPressure();
	info.type = m_type;

	return info;
}