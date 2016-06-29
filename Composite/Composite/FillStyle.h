#pragma once
#include "Color.h"

struct SFillStyle
{
	SColor color;

	bool operator == (const SFillStyle & s2) const
	{
		return color == s2.color ;
	}

	bool operator != (const SFillStyle & s2) const
	{
		return color != s2.color;
	}
};
