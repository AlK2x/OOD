#include "stdafx.h"
#include "Shape.h"

void CShape::SetLineStyle(SLineStyle style)
{
	m_lineStyle = style;
}

boost::optional<SLineStyle> CShape::GetLineStyle() const
{
	return m_lineStyle;
}

void CShape::SetFillStyle(SFillStyle style)
{
	m_fillStyle = style;
}

boost::optional<SFillStyle> CShape::GetFillStyle() const
{
	return m_fillStyle;
}

