#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(SPoint v1, SPoint v2, SPoint v3)
	:m_v1(v1), m_v2(v2), m_v3(v3)
{
}

void CTriangle::Draw(ICanvas & canvas) const
{
	canvas.DrawLine(m_v1, m_v2);
	canvas.DrawLine(m_v2, m_v3);
	canvas.DrawLine(m_v3, m_v1);
}

SPoint CTriangle::GetVertex1() const
{
	return m_v1;
}

SPoint CTriangle::GetVertex2() const
{
	return m_v2;
}

SPoint CTriangle::GetVertex3() const
{
	return m_v3;
}
