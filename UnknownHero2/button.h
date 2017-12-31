#pragma once
#include <SFML/Graphics.hpp>
#include "UserInteface.h"
#include "player.h"

class button
{
private:
	sf::Texture textureClicked, texture;
	sf::Sprite buttonSprite;
	sf::Time Wait_Time;
	sf::Clock time_since_click;
	UserInterface *UI;
	Player *player;
public:

	button(float position_x, float position_y, UserInterface* UI, Player* player)
	{
		texture.loadFromFile("button_green.png");
		textureClicked.loadFromFile("button_red.png");

		buttonSprite.setTexture(texture);
		buttonSprite.setPosition(position_x, position_y);
		buttonSprite.setScale(0.15f, 0.15f);
		buttonSprite.setOrigin(buttonSprite.getLocalBounds().width / 2, buttonSprite.getLocalBounds().height / 2);

		Wait_Time = sf::seconds(0.3f);

		this->UI = UI;
		this->player = player;
	}

	~button()
	{
	}

	bool check(sf::RenderWindow* window) {
		if (time_since_click.getElapsedTime() > Wait_Time) {
			buttonSprite.setTexture(texture);
			//If mouse is on button
			if (sf::Mouse::getPosition(*window).x > buttonSprite.getGlobalBounds().left && sf::Mouse::getPosition(*window).x < (buttonSprite.getGlobalBounds().left + buttonSprite.getGlobalBounds().width)) {
				if (sf::Mouse::getPosition(*window).y > buttonSprite.getGlobalBounds().top && sf::Mouse::getPosition(*window).y < (buttonSprite.getGlobalBounds().top + buttonSprite.getGlobalBounds().height)) {
					//and clicked
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						//Change button color
						buttonSprite.setTexture(textureClicked);
						std::cout << "click" << std::endl;
						time_since_click.restart();
						// Do Action
						return true;
					}
				}
			}
		}
		return false;
	}

	void draw(sf::RenderWindow *window) {
		window->draw(buttonSprite);
	}
};
