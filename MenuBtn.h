#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class MenuBtn
{
	public:
		sf::Text menuText;
		sf::Font font;
		sf::RectangleShape rect;

		MenuBtn(std::string btnText, int posX, int posY);
		MenuBtn(std::string btnText, sf::Font& font);

		void setPos();
};

