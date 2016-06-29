#pragma once
#include "Point.h"
#include "LineStyle.h"
#include "FillStyle.h"
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(SPoint a, SPoint b) = 0;
	virtual void DrawEllipse(int l, int t, int w, int h) = 0;

	virtual void FillEllipse(int l, int t, int w, int h, SColor color) = 0;
	virtual void FillPolygon(const std::vector<SPoint> & points, SColor color) = 0;

	virtual void SetPenColor(SColor color) = 0;
	virtual void SetPenThickness(unsigned thinckness) = 0;

	virtual void SetFillColor(SColor color) = 0;
};