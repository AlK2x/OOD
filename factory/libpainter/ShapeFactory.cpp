#include "stdafx.h"
#include "ShapeFactory.h"
#include "Rectangle.h"

CShapeFactory::CShapeFactory()
{
	m_callers["Rectangle"] = std::bind(&CShapeFactory::CreateRectangle, this, std::placeholders::_1);
	m_callers["Triangle"] = std::bind(&CShapeFactory::CreateTriangle, this, std::placeholders::_1);
	m_callers["RegularPoligon"] = std::bind(&CShapeFactory::CreateRegularPoligon, this, std::placeholders::_1);
	m_callers["Ellipse"] = std::bind(&CShapeFactory::CreateEllipse, this, std::placeholders::_1);
}

std::unique_ptr<CShape> CShapeFactory::CreateShape(const std::string & description)
{
	std::istringstream ss(description);

	std::string shapeDescr;
	ss >> shapeDescr;

	if (ss.fail() || ss.bad())
	{
		throw new std::runtime_error("Can't read shape");
	}

	return (m_callers.at(shapeDescr))(ss);
}

std::unique_ptr<CRectangle> CShapeFactory::CreateRectangle(std::istream & is)
{
	int x1, x2, y1, y2;
	is >> x1 >> y1 >> x2 >> y2;

	if (is.fail() || is.bad())
	{
		throw new std::runtime_error("Can't read rectangle parameters");
	}
	SPoint leftTop = { x1, y1 };
	SPoint rightBottom = { x2, y2 };
	return std::make_unique<CRectangle>(leftTop, rightBottom);
}

std::unique_ptr<CTriangle> CShapeFactory::CreateTriangle(std::istream & is)
{
	int x1, x2, y1, y2, x3, y3;
	is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (is.fail() || is.bad())
	{
		throw new std::runtime_error("Can't read triangle parameters");
	}
	SPoint v1 = { x1, y1 };
	SPoint v2 = { x2, y2 };
	SPoint v3 = { x3, y3 };

	return std::make_unique<CTriangle>(v1, v2, v3);
}

std::unique_ptr<CRegularPoligon> CShapeFactory::CreateRegularPoligon(std::istream & is)
{
	int x1, y1;
	unsigned r, v;
	is >> x1 >> y1 >> r >> v;

	if (is.fail() || is.bad())
	{
		throw new std::runtime_error("Can't read regular poligon parameters");
	}
	SPoint v1 = { x1, y1 };

	return std::make_unique<CRegularPoligon>(v1, r, v);
}

std::unique_ptr<CEllipse> CShapeFactory::CreateEllipse(std::istream & is)
{
	int x1, y1;
	unsigned h, v;
	is >> x1 >> y1 >> h >> v;

	if (is.fail() || is.bad())
	{
		throw new std::runtime_error("Can't read ellipse parameters");
	}
	SPoint v1 = { x1, y1 };

	return std::make_unique<CEllipse>(v1, h, v);
}

