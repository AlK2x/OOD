#include "stdafx.h"
#include "Canvas.h"

class EllipseShape : public sf::Shape
{
public:

	explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
		m_radius(radius)
	{
		update();
	}

	void setRadius(const sf::Vector2f& radius)
	{
		m_radius = radius;
		update();
	}

	const sf::Vector2f& getRadius() const
	{
		return m_radius;
	}

	std::size_t getPointCount() const
	{
		return 30;
	}

	sf::Vector2f getPoint(std::size_t index) const override
	{
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return sf::Vector2f(m_radius.x + x, m_radius.y + y);
	}

private:

	sf::Vector2f m_radius;

	
};

CCanvas::CCanvas(sf::RenderWindow & window)
	:m_window(window), m_color(sf::Color::Green)
{

}

CCanvas::~CCanvas()
{
}

void CCanvas::SetColor(Color color)
{
	switch (color)
	{
	case Color::Black:
		break;
	case Color::Blue:
		m_color.b = 255;
		break;
	case Color::Green:
		m_color.r = 0;
		m_color.g = 128;
		m_color.b = 0;
		break;
	case Color::Pink:
		m_color.r = 255;
		m_color.g = 192;
		m_color.b = 203;
		break;
	case Color::Red:
		m_color.r = 255;
		break;
	case Color::Yellow:
		m_color.r = 255;
		m_color.g = 255;
		break;
	default:
		break;
	}
}

void CCanvas::DrawLine(SPoint from, SPoint to)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(from.x, from.y), m_color),
		sf::Vertex(sf::Vector2f(to.x, to.y), m_color)
	};

	m_window.draw(line, 2, sf::Lines);
}

void CCanvas::DrawEllipse(int l, int t, int w, int h)
{
	EllipseShape ellipse(sf::Vector2f(w, h));

	ellipse.setOutlineThickness(0.5);
	ellipse.setOutlineColor(m_color);

	ellipse.setPosition(l, t);
	ellipse.setFillColor(m_filledColor);
	m_window.draw(ellipse);
}
