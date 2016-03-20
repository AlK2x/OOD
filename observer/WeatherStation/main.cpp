#include "stdafx.h"

#include "WeatherData.h"
#include "Display.h"
#include "StatsDisplay.h"
#include "BadWeatherData.h"

int main()
{
	CWeatherData outdoor;
	CWeatherData indoor;
	indoor.SetWeatherDataType(WeatherDataType::INDOOR);

	CDisplay display;
	outdoor.RegisterObserver(display);
	indoor.RegisterObserver(display);

	CStatsDisplay statsDisplay;
	display.priority = 10;
	outdoor.RegisterObserver(statsDisplay);

	indoor.SetMeasurements(42, 42, 42);
	outdoor.SetMeasurements(3, 0.7, 760);
	outdoor.SetMeasurements(4, 0.8, 761);

	outdoor.RemoveObserver(statsDisplay);

	CBadWeatherData bwd(outdoor);
	outdoor.RegisterObserver(bwd);
	outdoor.SetMeasurements(1, 2, 3);
	outdoor.SetMeasurements(4, 5, 6);

	return 0;
}