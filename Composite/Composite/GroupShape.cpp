#include "stdafx.h"
#include "GroupShape.h"

CGroupShape::CGroupShape()
{
}

void CGroupShape::AddShape(pShape shape)
{
	m_recalculateFrame = true;
	m_pShapes.emplace_back(shape);
}

void CGroupShape::Draw(ICanvas & canvas) const
{
	for (auto & pShape : m_pShapes)
	{
		pShape->Draw(canvas);
	}
}

void CGroupShape::SetLineStyle(SLineStyle style)
{
	for (auto & pShape : m_pShapes)
	{
		pShape->SetLineStyle(style);
	}
	m_lineStyle = style;
}

boost::optional<SLineStyle> CGroupShape::GetLineStyle() const
{
	boost::optional<SLineStyle> current;
	if (m_pShapes.size() > 0)
	{
		current = m_pShapes[0]->GetLineStyle();
	}

	if (std::all_of(m_pShapes.begin(), m_pShapes.end(), [&](pShape nextShape) {
		boost::optional<SLineStyle> next = nextShape->GetLineStyle();
		if (next == current)
		{
			return true;
		}
		current = next;
		return false;
	}))
	{
		return current;
	}

	return m_lineStyle;
}

void CGroupShape::SetFillStyle(SFillStyle style)
{
	for (auto & pShape : m_pShapes)
	{
		pShape->SetFillStyle(style);
	}
	m_fillStyle = style;
}

boost::optional<SFillStyle> CGroupShape::GetFillStyle() const
{
	boost::optional<SFillStyle> current;
	if (m_pShapes.size() > 0)
	{
		current = m_pShapes[0]->GetFillStyle();
	}

	if (std::all_of(m_pShapes.begin(), m_pShapes.end(), [&](pShape nextShape) {
		boost::optional<SFillStyle> next = nextShape->GetFillStyle();
		if (next == current)
		{
			return true;
		}
		current = next;
		return false;
	}))
	{
		return current;
	}

	return m_fillStyle;
}

CRectangle CGroupShape::GetFrame()
{
	if (m_recalculateFrame && m_pShapes.size() > 0)
	{
		int left, top, right, bottom;
		CRectangle frame = m_pShapes[0]->GetFrame();
		left = frame.GetLeftTop().x;
		top = frame.GetLeftTop().y;
		right = frame.GetRightBottom().x;
		bottom = frame.GetRightBottom().y;

		for (const auto & pShape : m_pShapes)
		{
			if (pShape->GetFrame().GetLeftTop().x < left) left = pShape->GetFrame().GetLeftTop().x;
			if (pShape->GetFrame().GetLeftTop().y < top)  top = pShape->GetFrame().GetLeftTop().y;
			if (pShape->GetFrame().GetRightBottom().x > right) right = pShape->GetFrame().GetRightBottom().x;
			if (pShape->GetFrame().GetRightBottom().y > bottom) bottom = pShape->GetFrame().GetRightBottom().y;
		}
		m_leftTopFrame.x = left;
		m_leftTopFrame.y = top;
		m_rightBottomFrame.x = right;
		m_rightBottomFrame.y = bottom;
	}
	
	return CRectangle(m_leftTopFrame, m_rightBottomFrame);
}

