#include "stdafx.h"
#include "../WeatherStation/SensorType.h"
#include "../WeatherStation/BadWeatherData.h"
#include "../WeatherStation/WeatherData.h"
#include "../WeatherStation/Display.h"
#include "../WeatherStation/StatsDisplay.h"
#include "../WeatherStation/SensorStatistic.h"
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

BOOST_AUTO_TEST_CASE(TestChangeObservsOrder)
{
	CDummyObservable dummyData;
	CDummyObserver dummyObserver1(1);

	CDummyObserver dummyObserver2(2);

	dummyData.RegisterObserver(dummyObserver1, 200);
	dummyData.RegisterObserver(dummyObserver2, 20);

	boost::test_tools::output_test_stream output;
	{
		CoutRedirect guard(output.rdbuf());
		dummyData.NotifyObservers();
	}

	BOOST_CHECK(output.is_equal("2\n1\n"));
}

BOOST_AUTO_TEST_CASE(WindBlowTwoTimesNorthOneSouth)
{
	CWindSensorStatistic s;
	s.Update(1, 90);
	s.Update(1, 90);
	s.Update(1, 270);
	BOOST_CHECK_CLOSE(s.GetAverage(), 90, 1e-5);
}

BOOST_AUTO_TEST_CASE(WindBlowTwoTimesSouthhOneNorth)
{
	CWindSensorStatistic s;
	s.Update(1, 270);
	s.Update(1, 270);
	s.Update(1, 90);
	BOOST_CHECK_CLOSE(s.GetAverage(), 270, 1e-5);
}

BOOST_AUTO_TEST_CASE(WindBlowTwoTimesWestOneEast)
{
	CWindSensorStatistic s;
	s.Update(1, 180);
	s.Update(1, 180);
	s.Update(1, 0);
	BOOST_CHECK_CLOSE(s.GetAverage(), 180, 1e-5);
}

BOOST_AUTO_TEST_CASE(WindBlowTwoTimesEastOneWest)
{
	CWindSensorStatistic s;
	s.Update(1, 0);
	s.Update(1, 0);
	s.Update(1, 180);
	BOOST_CHECK_CLOSE(s.GetAverage(), 0.0, 1e-5);
}

BOOST_AUTO_TEST_SUITE_END()