#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class MenuBtn
{
	public:
		sf::Text menuText;
		sf::Font font;
		sf::RectangleShape rect;

		MenuBtn(std::string btnText);
};

