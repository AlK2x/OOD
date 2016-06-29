#pragma once

class SColor
{
public:
	int r;
	int g;
	int b;
	int a;
};

class SLineStyle
{
public:
	SColor m_color;
};

class SFillStyle
{
public:
	SColor m_color;
	unsigned thickness;
};
