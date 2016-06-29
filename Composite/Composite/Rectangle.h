#pragma once
#include "Shape.h"
#include "ICanvas.h"

class CRectangle : public CShape
{
public:
	CRectangle(SPoint leftTop, SPoint rightBottom);
	~CRectangle() = default;

	void Draw(ICanvas & canvas) const;
	CRectangle GetFrame() override;
private:
	SPoint m_leftTop;
	SPoint m_rightBottom;
};

