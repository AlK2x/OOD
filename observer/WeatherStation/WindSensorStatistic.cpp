#include "stdafx.h"
#include "WindSensorStatistic.h"

bool IsEqual(double lhs, double rhs)
{
	return std::abs(lhs - rhs) < 1e-5;
}

void CWindSensorStatistic::Update(double speed, double angle)
{
	double angleInRad = (angle * M_PI) / 180;
	m_x += speed * std::cos(angleInRad);
	m_y += speed * std::sin(angleInRad);

	if (m_x > 0 && m_y >= 0)
	{
		m_average = std::atan(m_y / m_x) * 180 / M_PI;
	}
	else if (m_x <= 0 && m_y > 0)
	{
		m_average = (std::atan(std::abs(m_x) / m_y) + M_PI / 2) * 180 / M_PI;
	}
	else if (m_x < 0 && m_y <= 0)
	{
		m_average = (std::atan(std::abs(m_y) / std::abs(m_x)) + M_PI) * 180 / M_PI;
	}
	else
	{
		m_average = (std::atan(m_x / std::abs(m_y)) + 3 * M_PI / 2) * 180 / M_PI;
	}

	if (IsEqual(m_x, 0.0) && IsEqual(m_y, 0.0))
	{
		m_average = 0;
	}
}
