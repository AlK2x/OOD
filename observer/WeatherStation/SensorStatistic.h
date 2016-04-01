#pragma once

class CSensorStatistic
{
public:
	double GetAverage() const;
	double GetMin() const;
	double GetMax() const;

	void Update(double value);

	virtual ~CSensorStatistic() = default;

protected:
	double m_max = -std::numeric_limits<double>::infinity();
	double m_min = std::numeric_limits<double>::infinity();
	double m_average = 0;
	unsigned m_count = 0;
};
