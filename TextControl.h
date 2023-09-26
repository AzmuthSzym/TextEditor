#pragma once
#include <SFML/Graphics.hpp>

class TextControl
{
	public:
		sf::Text playerText;
		std::string playerInput;
		sf::Font font;

		TextControl();

		void changeCharSize(unsigned int newSize);
		void handleEvent(sf::Event event);
};

