#include "stdafx.h"
#include "WeatherData.h"
#include "Display.h"
#include "StatsDisplay.h"
#include "BadWeatherData.h"

int main()
{
	CWeatherData out(Location::Outdoor);
	CWeatherData  in(Location::Indoor);

	CDisplay display(&out);
	out.RegisterObserver(display);
	
	CStatsDisplay statsDisplay;
	out.RegisterObserver(statsDisplay);

	out.SetMeasurements(3, 0.7, 760);
	out.SetMeasurements(4, 0.8, 761);
	
	out.SetMeasurements(42, 42, 42);
	in.RegisterObserver(statsDisplay);
	in.SetMeasurements(1, 2, 3);

	return 0;
}