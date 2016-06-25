#pragma once
#include <sstream>
#include <map>
#include "IShapeFactory.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "RegularPoligon.h"
#include <functional>

class CShapeFactory : public IShapeFactory
{
public:

	CShapeFactory();
	~CShapeFactory() = default;

	std::unique_ptr<CShape> CreateShape(const std::string & description) override;

private:
	std::unique_ptr<CRectangle> CreateRectangle(std::istream & is);
	std::unique_ptr<CTriangle> CreateTriangle(std::istream & is);
	std::unique_ptr<CRegularPoligon> CreateRegularPoligon(std::istream & is);
	std::unique_ptr<CEllipse> CreateEllipse(std::istream & is);

	std::map < std::string, std::function<std::unique_ptr<CShape>(std::istream & is)>> m_callers;
};

