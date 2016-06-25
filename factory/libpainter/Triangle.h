#pragma once
#include "Shape.h"
#include "Point.h"

class CTriangle : public CShape
{
public:
	CTriangle(SPoint v1, SPoint v2, SPoint v3);

	~CTriangle() = default;

	virtual void Draw(ICanvas & canvas) const override;

	SPoint GetVertex1() const;
	SPoint GetVertex2() const;
	SPoint GetVertex3() const;

private:
	SPoint m_v1;
	SPoint m_v2;
	SPoint m_v3;
};

