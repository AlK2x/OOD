#pragma once
#include "Shape.h"
class CRegularPoligon : public CShape
{
public:
	CRegularPoligon(SPoint center, unsigned radius, unsigned vertexCount);
	~CRegularPoligon() = default;

	void Draw(ICanvas & canvas) const override;

	unsigned GetVertextCount() const;
	unsigned GetRadius() const;
	SPoint GetCenter() const;

private:
	SPoint m_center;
	unsigned m_radius;
	unsigned m_vertextCount;
};

