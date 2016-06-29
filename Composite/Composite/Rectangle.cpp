#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(SPoint leftTop, SPoint rightBottom)
	:m_leftTop(leftTop), m_rightBottom(rightBottom)
{
}

SPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

SPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

void CRectangle::Draw(ICanvas & canvas) const
{
	boost::optional<SLineStyle> lineStyle = GetLineStyle();
	if (lineStyle)
	{
		canvas.SetPenColor(lineStyle->color);
		canvas.SetPenThickness(lineStyle->thickness);
	}

	SPoint rightTop = { m_rightBottom.x, m_leftTop.y };
	SPoint leftBottom = { m_leftTop.x, m_rightBottom.y };
	canvas.DrawLine(m_leftTop, rightTop);
	canvas.DrawLine(rightTop, m_rightBottom);
	canvas.DrawLine(m_rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, m_leftTop);
}

CRectangle CRectangle::GetFrame()
{
	CRectangle rect(m_leftTop, m_rightBottom);
	return rect;
}

