#pragma once
#include "IShapeFactory.h"
#include "Shape.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();
	~CShapeFactory();

	virtual std::unique_ptr<CShape> CreateShape(const std::string & description) override;
};

