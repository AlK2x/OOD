#pragma once
#include "Color.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(int from, int to) = 0;
	virtual void DrawEllipse(int l, int t, int w, int h) = 0;

	virtual ~ICanvas() = default;
};