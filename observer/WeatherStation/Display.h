#pragma once
#include "stdafx.h"
#include "IObserver.h"
#include "WeatherInfo.h"

class CDisplay : public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override;
private:

	void DisplayData(SWeatherInfo const & data) const;

	SWeatherInfo m_inData;
	SWeatherInfo m_outData;
};
