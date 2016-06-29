#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(SPoint leftTop, SPoint rightBottom)
	:m_leftTop(leftTop), m_rightBottom(rightBottom)
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::Draw(ICanvas & canvas) const
{
	boost::optional<SLineStyle> lineStyle = GetLineStyle();
	if (lineStyle)
	{
		//canvas.SetPenColor(lineStyle.get().color);
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
	return CRectangle(m_leftTop, m_rightBottom);
}
