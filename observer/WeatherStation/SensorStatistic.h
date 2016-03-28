#pragma once
#include "stdafx.h"

class CSensorStatistic
{
public:
	double GetAverage() const;
	double getMin() const;
	double getMax() const;

	void Update(double value);

	virtual ~CSensorStatistic() = default;
protected:
	virtual void updateImpl(double value);

private:
	double m_max = -std::numeric_limits<double>::infinity();
	double m_min = std::numeric_limits<double>::infinity();
	double m_average = 0;
	unsigned m_count = 0;
};

