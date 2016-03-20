#pragma once
#include "stdafx.h"
#include "SensorType.h"
#include "WeatherData.h"
#include "WeatherInfo.h"
#include "IObserver.h"
#include "SensorStats.h"

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay();
	void Update(SWeatherInfo const& data) override;
private:
	void DisplayData(CSensorStats const & stats) const;

	CSensorStats m_inData;
	CSensorStats m_outData;
};
