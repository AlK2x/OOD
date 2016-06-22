#pragma once
#include "Point.h"
#include "Color.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(SPoint from, SPoint to) = 0;
	virtual void DrawEllipse(int l, int t, int w, int h) = 0;

	virtual ~ICanvas() = default;
};