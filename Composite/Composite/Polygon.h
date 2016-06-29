#pragma once
#include "Shape.h"
class CPolygon : public CShape
{
public:
	CPolygon();
	~CPolygon() = default;

	virtual void Draw(ICanvas & canvas) const;
	virtual CRectangle GetFrame() override;
};

