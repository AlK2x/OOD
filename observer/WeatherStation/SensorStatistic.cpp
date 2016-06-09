#include "stdafx.h"
#include "SensorStatistic.h"

double CSensorStatistic::GetAverage() const
{
	return m_average;
}

double CSensorStatistic::GetMin() const
{
	return m_min;
}

double CSensorStatistic::GetMax() const
{
	return m_max;
}

void CSensorStatistic::Update(double value)
{
	++m_count;
	m_max = std::max(m_max, value);
	m_min = std::min(m_min, value);
	m_average = (value + m_average) / m_count;
}

