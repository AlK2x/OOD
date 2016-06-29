#pragma once
#include "ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas();
	~CCanvas() = default;

	void DrawLine(SPoint a, SPoint b) override;
	void DrawEllipse(int l, int t, int w, int h) override;
	void FillEllipse(int l, int t, int w, int h, SColor color) override;
	void FillPolygon(const std::vector<SPoint>& points, SColor color) override;
	void SetPenColor(SColor color) override;
	void SetPenThickness(unsigned thinckness) override;
	void SetFillColor(SColor color) override;
};

