#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(SPoint leftTop, SPoint rightBottom)
	:m_leftTop(leftTop), m_rightBottom(rightBottom)
{
}

void CRectangle::GetLeftTop() const
{
}


void CRectangle::GetRightBottom() const
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::Draw(ICanvas & canvas) const
{
	SPoint rightTop = { m_rightBottom.x, m_leftTop.y };
	SPoint leftBottom = { m_leftTop.x, m_rightBottom.y };
	canvas.DrawLine(m_leftTop, rightTop);
	canvas.DrawLine(rightTop, m_rightBottom);
	canvas.DrawLine(m_rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, m_leftTop);
}
