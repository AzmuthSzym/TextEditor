#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TextControl.h"
#include "Menu.h"
#include "MenuBtn.h"
#include <Windows.h>
#include <vector>


int main()
{
    //Get screen resolution (works only on windows thanks to windows.h library)
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);

    sf::RenderWindow window(sf::VideoMode(x, y), "Text Editor");

    sf::Font mainFont;
    mainFont.loadFromFile("MotionPicture_PersonalUseOnly.ttf");

    TextControl UserText;
    sf::Transform transformTxt;
    std::vector<MenuBtn> menuVector{ MenuBtn("File", mainFont), MenuBtn("Close", mainFont) };
    
    transformTxt.translate(20, 100);

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
            for (auto& menuBtn : menuVector)
            {
                if (menuBtn.rect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    menuBtn.menuText.setFillColor(sf::Color::Blue);
                }
            }
            
        }

        window.clear();
        for (int i = 0; i < menuVector.size(); i++)
        {
            int test = 10 + (130 * i);
            menuVector[i].rect.setPosition(test, 10);
            menuVector[i].setPos();
            window.draw(menuVector[i].rect);
            window.draw(menuVector[i].menuText);
        }

        window.draw(UserText.playerText, transformTxt);
        window.display();
    }

    return 0;
}