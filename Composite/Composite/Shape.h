#pragma once
#include "ICanvas.h"
#include "LineStyle.h"
#include "Rectangle.h"
#include <boost\optional.hpp>

class IDrawable
{
public:
	virtual void Draw(ICanvas & canvas) const = 0;
};

class CShape
{
public:

	virtual void SetLineStyle(SLineStyle style);
	virtual boost::optional<SLineStyle> GetLineStyle() const;

	virtual void SetFillStyle(SFillStyle style);
	virtual boost::optional<SFillStyle> GetFillStyle() const;

	virtual CRectangle GetFrame() = 0;

	virtual ~CShape() = default;

protected:
	boost::optional<SLineStyle> m_lineStyle;
	boost::optional<SFillStyle> m_fillStyle;
};

