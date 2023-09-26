#include "MenuBtn.h"

MenuBtn::MenuBtn(std::string btnText)
{
	this->rect.setSize(sf::Vector2f(120, 50));

	this->font.loadFromFile("MotionPicture_PersonalUseOnly.ttf");
	this->menuText.setFont(font);
	this->menuText.setCharacterSize(40);
	this->menuText.setFillColor(sf::Color::Black);
	this->menuText.setOutlineColor(sf::Color::Yellow);
	this->menuText.setOutlineThickness(0.5f);
	this->menuText.setString(btnText);
	this->menuText.setOrigin(this->menuText.getGlobalBounds().getSize() / 2.f + this->menuText.getLocalBounds().getPosition());
	this->menuText.setPosition(this->rect.getPosition() + (this->rect.getSize() / 2.f));

}