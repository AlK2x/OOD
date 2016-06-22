#include "stdafx.h"
#include "../libpainter/Designer.h"
#include "../libpainter/Point.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"
#include "SDL.h"
#include "SDLCanvas.h"

#undef main


using namespace std;

int main()
{
	SDLCanvas canvas;
	canvas.SetColor(Color::Pink);
	canvas.DrawLine({ 10, 100 }, { 20, 200 });


	CShapeFactory f;
	CDesigner designer(f);
	auto d = designer.CreateDraft(cin);

	return 0;
}

