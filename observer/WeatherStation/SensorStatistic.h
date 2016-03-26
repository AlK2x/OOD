#pragma once
#include "stdafx.h"

class CSensorStatistic
{
public:
	double GetAverage() const;
	double getMin() const;
	double getMax() const;

	void Update(double value);

	~CSensorStatistic() = default;
private:
	double m_max = -std::numeric_limits<double>::infinity();
	double m_min = std::numeric_limits<double>::infinity();
	double m_average = 0;
	unsigned m_count = 0;
};

