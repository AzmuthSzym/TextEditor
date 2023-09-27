#include "MenuBtn.h"

MenuBtn::MenuBtn(std::string btnText, int posX, int posY)
{
	this->rect.setSize(sf::Vector2f(posX, posY));
	this->menuText.setFont(font);
	this->menuText.setCharacterSize(40);
	this->menuText.setFillColor(sf::Color::Black);
	this->menuText.setOutlineColor(sf::Color::Yellow);
	this->menuText.setOutlineThickness(0.5f);
	this->menuText.setString(btnText);
	this->menuText.setOrigin(this->menuText.getGlobalBounds().getSize() / 2.f + this->menuText.getLocalBounds().getPosition());
	this->menuText.setPosition(this->rect.getPosition() + (this->rect.getSize() / 2.f));

}

MenuBtn::MenuBtn(std::string btnText, sf::Font &font)
{
	this->rect.setSize(sf::Vector2f(120, 50));

	this->font = font;
	this->menuText.setFont(font);
	this->menuText.setCharacterSize(40);
	this->menuText.setFillColor(sf::Color::Black);
	this->menuText.setOutlineColor(sf::Color::Yellow);
	this->menuText.setOutlineThickness(0.5f);
	this->menuText.setString(btnText);


}

void MenuBtn::setPos()
{
	this->menuText.setOrigin(this->menuText.getGlobalBounds().getSize() / 2.f + this->menuText.getLocalBounds().getPosition());
	this->menuText.setPosition(this->rect.getPosition() + (this->rect.getSize() / 2.f));
}