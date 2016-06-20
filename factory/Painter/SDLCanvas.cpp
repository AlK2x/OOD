#include "stdafx.h"
#include "SDLCanvas.h"

SDLCanvas::SDLCanvas()
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow (
		"Painter",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
}


SDLCanvas::~SDLCanvas()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void SDLCanvas::SetColor(Color color)
{
	RGBColor c{ 0, 0, 0 };
	switch (color)
	{
		case Color::Black:
			break;
		case Color::Blue:
			c.b = 255;
			break;
		case Color::Green:
			c.r = 0;
			c.g = 128;
			c.b = 0;
			break;
		case Color::Pink:
			c.r = 255;
			c.g = 192;
			c.b = 203;
			break;
		case Color::Red:
			c.r = 255;
			break;
		case Color::Yellow:
			c.r = 255;
			c.g = 255;
			break;
		default:
			break;
	}

	SetColorImpl(c);
}

void SDLCanvas::DrawLine(SPoint from, SPoint to)
{
	SDL_RenderDrawLine(m_renderer, from.x, from.y, to.x, to.y);
	SDL_RenderPresent(m_renderer);
}

void SDLCanvas::DrawEllipse(int l, int t, int w, int h)
{
	
	(void)l;
	(void)t;
	(void)w;
	(void)h;
}

void SDLCanvas::SetColorImpl(RGBColor color)
{
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, 255);
}
