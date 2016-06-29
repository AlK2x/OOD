#pragma once
#include "Shape.h"
#include "Point.h"

class CRectangle : public CShape
{
public:
	CRectangle(SPoint leftTop, SPoint rightBottom);
	SPoint GetLeftTop() const;
	SPoint GetRightBottom() const;

	~CRectangle() = default;

	void Draw(ICanvas & canvas) const;
	CRectangle GetFrame() override;
private:
	SPoint m_leftTop;
	SPoint m_rightBottom;

};

