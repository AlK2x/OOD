#pragma once
#include "SensorStatistic.h"

class CWindSensorStatistic : public CSensorStatistic
{
public:
	void Update(double speed, double angle);
private:
	double m_x = 0.0;
	double m_y = 0.0;
};

