#pragma once
#include "IDrawable.h"
#include "LineStyle.h"
#include "FillStyle.h"

class CRectangle;
class CShape;

typedef std::shared_ptr<CShape> pShape;


class CShape : public IDrawable
{
public:
	
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

