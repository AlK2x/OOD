#include "stdafx.h"
#include "Polygon.h"


CPolygon::CPolygon()
{
}

void CPolygon::Draw(ICanvas & canvas) const
{
}

CRectangle CPolygon::GetFrame()
{
	SPoint rightTop = { 1, 1 };
	SPoint leftBottom = { 1, 1 };
	return CRectangle(leftBottom, rightTop);
}
