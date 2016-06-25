#include "stdafx.h"
#include "Ellipse.h"


CEllipse::CEllipse(SPoint center, unsigned horizontalRadius, unsigned vertexRadius)
	:m_center(center), m_h(horizontalRadius), m_v(vertexRadius)
{
}

void CEllipse::Draw(ICanvas & canvas) const
{
	canvas.DrawEllipse(m_center.x, m_center.y, m_h * 2, m_v * 2);
}

SPoint CEllipse::GetCenter() const
{
	return m_center;
}

unsigned CEllipse::GetHorizontalRadius() const
{
	return m_h;
}

unsigned CEllipse::GetVerticalRadius() const
{
	return m_v;
}
