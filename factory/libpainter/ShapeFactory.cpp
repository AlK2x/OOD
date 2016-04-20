#include "stdafx.h"
#include "ShapeFactory.h"

CShapeFactory::CShapeFactory()
{
}


CShapeFactory::~CShapeFactory()
{
}

std::unique_ptr<CShape> CShapeFactory::CreateShape(const std::string & description)
{
	(void)description;
	return std::make_unique<CShape>();
}
