#pragma once
#include "stdafx.h"
#include "IObserver.h"
#include "WeatherInfo.h"

class CDisplay : public IObserver<SWeatherInfo>
{
public:
	void Update(SWeatherInfo const& data) override;
};
