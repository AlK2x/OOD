#pragma once
#include "Shape.h"
#include "Point.h"

class CRectangle : public CShape
{
public:
	CRectangle();
	void GetLeftTop() const;
	void GetRightBottom() const;
	~CRectangle();

private:
	SPoint m_leftTop;
	SPoint m_rightBottom;
};

