#pragma once
#include "ICanvas.h"

class CShape
{
public:
	CShape();
	
	virtual void Draw(ICanvas & canvas) const = 0;

	virtual ~CShape();
};

