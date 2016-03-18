#include "stdafx.h"
#include "BadWeatherData.h"

CBadWeatherData::CBadWeatherData(IObservable<SWeatherInfo>& wd)
	:m_wd(wd)
{
}

void CBadWeatherData::Update(SWeatherInfo const & data)
{
	m_wd.RemoveObserver(*this);
}
