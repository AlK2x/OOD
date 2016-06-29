#pragma once
#include "Color.h"

struct SLineStyle
{
	SLineStyle() :thickness(0) {}
	SColor color;
	unsigned thickness;

	bool operator == (const SLineStyle & s2) const
	{
		return color == s2.color && thickness == s2.thickness;
	}

	bool operator != (const SLineStyle & s2) const
	{
		return thickness != s2.thickness && color != s2.color;
	}
};

