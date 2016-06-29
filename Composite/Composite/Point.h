#pragma once
#include <ostream>

struct SPoint
{
	SPoint() : x(0), y(0) {}
	SPoint(const int a, const int b) : x(a), y(b) {}
	int x;
	int y;

	friend std::ostream& operator<< (std::ostream & os, const SPoint & p)
	{
		os << '(' << p.x << ':' << p.y << ')';
		return os;
	}
};

