#include "stdafx.h"
#include "Canvas.h"


CCanvas::CCanvas()
{
}

void CCanvas::DrawLine(SPoint a, SPoint b)
{
	std::cout << "Line: " << a << " - " << b << std::endl;
}

void CCanvas::DrawEllipse(int l, int t, int w, int h)
{
	std::cout << "Draw Ellipse" << std::endl;
}

void CCanvas::FillEllipse(int l, int t, int w, int h, SColor color)
{
	std::cout << "Fill Ellipse" << std::endl;
}

void CCanvas::FillPolygon(const std::vector<SPoint>& points, SColor color)
{
	std::cout << "Fill Polygon" << std::endl;
}

void CCanvas::SetPenColor(SColor color)
{
}

void CCanvas::SetPenThickness(unsigned thinckness)
{
}

void CCanvas::SetFillColor(SColor color)
{
}
