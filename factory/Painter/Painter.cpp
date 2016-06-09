// Painter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../libpainter/Designer.h"
#include "../libpainter/Point.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"

using namespace std;

int main()
{
	CShapeFactory f;
	CDesigner designer(f);
	auto d = designer.CreateDraft(cin);

	return 0;
}

