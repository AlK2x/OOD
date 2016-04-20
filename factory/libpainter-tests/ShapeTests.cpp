#include "stdafx.h"
#include "../libpainter/Shape.h"
#include "../libpainter/ICanvas.h"

class CMockCanvas : public ICanvas
{
public:
	virtual void SetColor(Color color) override
	{
		_color = color;
	}

	virtual void DrawLine(int from, int to) override
	{
		(void)from;
		(void)to;
	}

	virtual void DrawEllipse(int l, int t, int w, int h) override
	{
		(void)l;
		(void)t;
		(void)w;
		(void)h;
	}

	Color _color;
	int _from;
};

BOOST_AUTO_TEST_SUITE(shapes)


BOOST_AUTO_TEST_SUITE_END()