#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
class UserInterface;

class button
{
private:
	sf::Texture textureClicked, texture;
	sf::Sprite buttonSprite;
	sf::Time Wait_Time;
	sf::Clock time_since_click;
	UserInterface* UI = NULL;
public:

	button(float position_x, float position_y, UserInterface* UI , std::string texturepath , std::string texturepathclicked )
	{
		texture.loadFromFile(texturepath);
		textureClicked.loadFromFile(texturepathclicked);

		buttonSprite.setTexture(texture);
		buttonSprite.setPosition(position_x, position_y);
		buttonSprite.setScale(0.15f, 0.15f);
		buttonSprite.setOrigin(buttonSprite.getLocalBounds().width / 2, buttonSprite.getLocalBounds().height / 2);

		Wait_Time = sf::seconds(0.3f);

		this->UI = UI;
	}

	button(UserInterface* UI)
	{
		texture.loadFromFile("images/button_green.png");
		textureClicked.loadFromFile("images/button_red.png");

		buttonSprite.setTexture(texture);
		buttonSprite.setScale(0.15f, 0.15f);
		buttonSprite.setOrigin(buttonSprite.getLocalBounds().width / 2, buttonSprite.getLocalBounds().height / 2);

		Wait_Time = sf::seconds(0.3f);

		this->UI = UI;
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

	void setPosition(float x, float y) {
		buttonSprite.setPosition(x, y);
	}

	void scale(float factor_x, float factor_y) {
		buttonSprite.scale(factor_x, factor_y);
	}
};
#endif