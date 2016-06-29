#pragma once
#include "Shape.h"
#include "Rectangle.h"

class CGroupShape : public CShape
{
public:
	CGroupShape();

	~CGroupShape() = default;

	void AddShape(pShape shape);

	virtual void Draw(ICanvas & canvas) const override;
	void SetLineStyle(SLineStyle style) override;
	virtual boost::optional<SLineStyle> GetLineStyle() const override;

	void SetFillStyle(SFillStyle style) override;
	boost::optional<SFillStyle> GetFillStyle() const override;
	virtual CRectangle GetFrame() override;
private:
	std::vector<pShape> m_pShapes;

	SPoint m_leftTopFrame;
	SPoint m_rightBottomFrame;
	bool m_recalculateFrame;
};

