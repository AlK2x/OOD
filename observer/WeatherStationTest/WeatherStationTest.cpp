#include "stdafx.h"
#include "../WeatherStation/SensorType.h"
#include "../WeatherStation/BadWeatherData.h"
#include "../WeatherStation/WeatherData.h"
#include "../WeatherStation/Display.h"
#include "../WeatherStation/StatsDisplay.h"
#include "DummyObserver.h"
#include "DummyObservable.h"

BOOST_AUTO_TEST_SUITE(WeatherStationTests)

struct CoutRedirect
{
	CoutRedirect(std::streambuf * newBuffer)
		:old(std::cout.rdbuf(newBuffer))
	{}

	~CoutRedirect()
	{
		std::cout.rdbuf(old);
	}

private:
	std::streambuf * old;
};

BOOST_AUTO_TEST_CASE(TestSelfDelete)
{
	CWeatherData wd;
	CBadWeatherData bwd(wd);
	wd.RegisterObserver(bwd);

	wd.SetMeasurements(1, 2, 4);
	wd.SetMeasurements(3, 4, 5);

	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(TestChangeObservsOrder)
{
	CDummyObservable dummyData;
	CDummyObserver dummyObserver1(1);
	dummyObserver1.priority = 1;
	CDummyObserver dummyObserver2(2);
	dummyObserver2.priority = 2;

	dummyData.RegisterObserver(dummyObserver1);
	dummyData.RegisterObserver(dummyObserver2);

	boost::test_tools::output_test_stream output;
	{
		CoutRedirect guard(output.rdbuf());
		dummyData.NotifyObservers();
	}

	BOOST_CHECK(output.is_equal("2\n1\n"));
}

BOOST_AUTO_TEST_CASE(TestIndoorOutdoorSensor)
{
	CWeatherData indoor;
	indoor.SetWeatherDataType(WeatherDataType::INDOOR);
	CWeatherData outdoor;
}

BOOST_AUTO_TEST_SUITE_END()