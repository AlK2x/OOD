#pragma once
#include "../libpainter/ICanvas.h"
#include <SDL.h>
#include <SDL_render.h>

class SDLCanvas : public ICanvas
{
public:
	SDLCanvas();
	~SDLCanvas();

	void SetColor(Color color) override;
	void DrawLine(SPoint from, SPoint to) override;
	void DrawEllipse(int l, int t, int w, int h) override;

private:

	struct RGBColor
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
	};


	void SetColorImpl(RGBColor color);

	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
};

