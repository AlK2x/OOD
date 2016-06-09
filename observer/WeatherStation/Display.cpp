#include "stdafx.h"
#include "Display.h"

void CDisplay::Update(IObservable<SWeatherInfo> const& subject)
{
	if (&subject == m_subject)
	{
		std::cout << "Tempearure: " << m_subject->GetTemperature() << std::endl;
		std::cout << "Pressure  : " << m_subject->GetPressure() << std::endl;
		std::cout << "Humidity  : " << m_subject->GetHumidity() << std::endl;

		std::cout << "----------------" << std::endl;
	}
}
