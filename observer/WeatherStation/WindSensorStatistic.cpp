#include "stdafx.h"
#include "WindSensorStatistic.h"

void CWindSensorStatistic::Update(double speed, double angle)
{
	double angleInRad = (angle * M_PI) / 180;
	m_x += speed * std::cos(angleInRad);
	m_y += speed * std::sin(angleInRad);

	if (m_x >= 0 && m_y >= 0)
	{
		m_average = std::atan(m_y / m_x) * 180 / M_PI;
	}
	else if (m_x < 0 && m_y >= 0)
	{
		m_average = (std::atan(m_y / m_x) + M_PI / 2) * 180 / M_PI;
	}
	else if (m_x < 0 && m_y < 0)
	{
		m_average = (std::atan(m_y / m_x) + M_PI) * 180 / M_PI;
	}
	else
	{
		m_average = (std::atan(m_x / m_y) + 3 * M_PI / 2) * 180 / M_PI;
	}
}
