#pragma once
#include "..\libpainter\ICanvas.h"
#include <SFML\Graphics.hpp>

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::RenderWindow & window);
	~CCanvas();

	virtual void SetColor(Color color) override;
	virtual void DrawLine(SPoint from, SPoint to) override;
	virtual void DrawEllipse(int l, int t, int w, int h) override;

private:
	sf::RenderWindow & m_window;
	sf::Color m_color;
	sf::Color m_filledColor = sf::Color(0,0,0,255);
};

