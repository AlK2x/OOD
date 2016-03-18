#include "stdafx.h"
#include "../WeatherStation/SensorType.h"
#include "../WeatherStation/BadWeatherData.h"
#include "../WeatherStation/WeatherData.h"
#include "../WeatherStation/Display.h"
#include "../WeatherStation/StatsDisplay.h"


BOOST_AUTO_TEST_CASE(TestSelfDelete)
{
	CWeatherData wd;
	CBadWeatherData bwd(wd);
	wd.RegisterObserver(bwd);

	wd.SetMeasurements(1, 2, 4);
	wd.SetMeasurements(3, 4, 5);

	BOOST_CHECK(true);
}
