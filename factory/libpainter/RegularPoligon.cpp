#include "stdafx.h"
#include "RegularPoligon.h"


CRegularPoligon::CRegularPoligon(SPoint center, unsigned radius, unsigned vertexCount)
	:m_center(center), m_radius(radius), m_vertextCount(vertexCount)
{
}

void CRegularPoligon::Draw(ICanvas & canvas) const
{
	int x = m_center.x;
	int y = m_center.y + m_radius;

	SPoint p1 = { x, y };
	SPoint p2 = { 0, 0 };

	for (unsigned i = 1; i < m_vertextCount; ++i)
	{
		x = m_center.x + static_cast<int>(m_radius * cos(2 * M_PI * i / m_vertextCount));
		y = m_center.y + static_cast<int>(m_radius * sin(2 * M_PI * i / m_vertextCount));

		p2.x = x;
		p2.y = y;
		canvas.DrawLine(p1, p2);
		p1.x = p2.x;
		p1.y = p2.y;
	}
}

unsigned CRegularPoligon::GetVertextCount() const
{
	return m_vertextCount;
}

unsigned CRegularPoligon::GetRadius() const
{
	return m_radius;
}

SPoint CRegularPoligon::GetCenter() const
{
	return m_center;
}
