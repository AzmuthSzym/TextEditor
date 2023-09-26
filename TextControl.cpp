#include "TextControl.h"

TextControl::TextControl()
{
	//this->font.loadFromFile("Boldest Romance.otf");
	this->font.loadFromFile("SouthernAire_Personal_Use_Only.ttf");
	this->playerText.setFont(font);
	this->playerText.setCharacterSize(60);
}

void TextControl::changeCharSize(unsigned int newSize)
{
	this->playerText.setCharacterSize(newSize);
}

void TextControl::handleEvent(sf::Event event)
{
	if (event.text.unicode == '\b' && !this->playerInput.empty())
	{
		this->playerInput.erase(this->playerInput.size() - 1, 1);
	}
	//else if (event.text.unicode < 128)
	else
	{
		this->playerInput += event.text.unicode;
	}
	this->playerText.setString(this->playerInput);
}