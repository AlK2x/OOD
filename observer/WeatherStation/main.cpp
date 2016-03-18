#include "stdafx.h"

#include "WeatherData.h"
#include "Display.h"
#include "StatsDisplay.h"
#include "BadWeatherData.h"

int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display);

	CStatsDisplay statsDisplay;
	display.priority = 10;
	wd.RegisterObserver(statsDisplay);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay);

	CBadWeatherData bwd(wd);
	wd.RegisterObserver(bwd);
	wd.SetMeasurements(1, 2, 3);
	wd.SetMeasurements(4, 5, 6);

	return 0;
}