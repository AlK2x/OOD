#pragma once

#include "../libpainter/Designer.h"
#include "../libpainter/PictureDraft.h"
#include "../libpainter/IShapeFactory.h"

using namespace std;
using boost::algorithm::all_of;
using boost::copy;

class CMockShape : public CShape
{
public:
	CMockShape(const string& descr)
		:descr(descr)
	{
	}
	string descr;

	virtual void Draw(ICanvas & canvas) const override
	{
		(void)canvas;
	}
};
