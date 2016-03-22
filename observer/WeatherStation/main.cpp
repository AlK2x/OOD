#include "stdafx.h"
#include "WeatherData.h"
#include "Display.h"
#include "StatsDisplay.h"
#include "BadWeatherData.h"

int main()
{
	CWeatherData outdoor;

	CDisplay display;
	outdoor.RegisterObserver(display, 10);

	CStatsDisplay statsDisplay;
	outdoor.RegisterObserver(statsDisplay);

	outdoor.SetMeasurements(3, 0.7, 760);
	outdoor.SetMeasurements(4, 0.8, 761);

	return 0;
}