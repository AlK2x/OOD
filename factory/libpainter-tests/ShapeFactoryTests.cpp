#include "stdafx.h"
#include "../libpainter/ShapeFactory.h"

using namespace std;

struct Shape_factory_
{
	CShapeFactory factory;
};

BOOST_FIXTURE_TEST_SUITE(Shape_factory, Shape_factory_)
	BOOST_AUTO_TEST_SUITE(can_create_shapes)
		BOOST_AUTO_TEST_CASE(empty_on_empty_input)
		{
			std::unique_ptr<CShape> shape = factory.CreateShape("");
		}

	BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()