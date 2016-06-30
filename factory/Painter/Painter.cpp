#include "stdafx.h"
#include "../libpainter/Designer.h"
#include "../libpainter/Point.h"
#include "../libpainter/ShapeFactory.h"
#include "../libpainter/PictureDraft.h"
#include "Canvas.h"

#include <SFML\Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	CCanvas canvas(window);
	sf::CircleShape shape(100.f);
	sf::RectangleShape rect(sf::Vector2f(120, 50));

	/*std::string pic = "Rectangle 10 10 100 100 \nEllipse 10 10 10 20";
	std::istringstream ss(pic);
*/
	CShapeFactory f;
	CDesigner designer(f);
	//auto draft = designer.CreateDraft(ss);
	try
	{
		auto draft = designer.CreateDraft(cin);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			for (const auto & s : draft)
			{
				s.Draw(canvas);
				//window.display();
			}
			window.display();

		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}

