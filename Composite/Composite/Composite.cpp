#include "stdafx.h"
#include "Rectangle.h"
#include "GroupShape.h"
#include "Point.h"

using namespace std;

int main()
{
	pShape r1 = std::make_shared<CRectangle>(SPoint{ 1,2 }, SPoint{ 3, 4 });
	pShape r2 = std::make_shared<CRectangle>(SPoint{ 0,2 }, SPoint{ 3, 40 });

	SLineStyle style;
	style.color = 0x123456;
	r1->SetLineStyle(style);

	style.color = 0x123457;
	r2->SetLineStyle(style);

	CGroupShape group;
	group.AddShape(r1);
	group.AddShape(r2);

	boost::optional<SLineStyle> st = group.GetLineStyle();
	if (st)
	{
		cout << st->color << endl;
	}
	else
	{
		cout << "wrong" << endl;
	}

	CRectangle frame = group.GetFrame();
	cout << "x1: " << frame.GetLeftTop().x << " y1: " << frame.GetLeftTop().y  << endl;
	cout << "x2: " << frame.GetRightBottom().x << " y2: " << frame.GetRightBottom().y << endl;

    return 0;
}

