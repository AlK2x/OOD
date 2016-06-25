#pragma once
#include "Shape.h"
class CEllipse : public CShape
{
public:
	CEllipse(SPoint center, unsigned horizontalRadius, unsigned vertexRadius);
	~CEllipse() = default;

	void Draw(ICanvas & canvas) const override;
	SPoint GetCenter() const;

	unsigned GetHorizontalRadius() const;
	unsigned GetVerticalRadius() const;

private:
	SPoint m_center;
	unsigned m_h;
	unsigned m_v;
};

