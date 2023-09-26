#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TextControl.h"
#include "MenuBtn.h"
#include <iostream>
#include <Windows.h>

int main()
{
    //Get screen resolution (works only on windows thanks to windows.h library)
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);

    TextControl UserText;
    MenuBtn menu("File");

    sf::Transform transformTxt;
    transformTxt.translate(20, 100);
    sf::Transform transformRect;
    transformRect.translate(10, 10);

    sf::RenderWindow window(sf::VideoMode(x, y), "Text Editor");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered)
            {
                UserText.handleEvent(event);
            }
            if (menu.rect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                menu.menuText.setFillColor(sf::Color::Blue);
            }
            
        }

        window.clear();

        window.draw(menu.rect, transformRect);
        window.draw(menu.menuText, transformRect);

        window.draw(UserText.playerText, transformTxt);
        window.display();
    }

    return 0;
}