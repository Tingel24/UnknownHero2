#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "player.h"
#include "button.h"
#include "UserInteface.h"
class Item
{
private:
	sf::Text Itemdescription;
	sf::Text Amount;
	sf::Texture Itemtexture;
	sf::Sprite Itemsprite;
	sf::Font font;
	button* Usebutton;
	int usage;
	
public:
	int itemtype; //0 for health, 1 for attack, 2 for defense

	Item(std::string itemtext, sf::Font* font, sf::Color color, std::string itemtexturepath, int amount,UserInterface* UI,int itemtype)
	{
		this->font = *font;
		usage = amount;
		this->itemtype = itemtype;

		Usebutton = new button(UI);

		Itemdescription.setFont(*font);
		Itemdescription.setString(itemtext);
		Itemdescription.setCharacterSize(24);
		Itemdescription.setFillColor(color);
		Itemdescription.setOrigin(0, Itemdescription.getLocalBounds().height / 2);

		Amount.setFont(*font);
		Amount.setString(std::to_string(usage));
		Amount.setCharacterSize(24);
		Amount.setFillColor(color);
		Amount.setOrigin(0, Amount.getLocalBounds().height / 2);

		Itemtexture.loadFromFile(itemtexturepath);
		Itemsprite.setTexture(Itemtexture);
		Itemsprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
		Itemsprite.setOrigin(Itemsprite.getLocalBounds().width / 2, Itemsprite.getLocalBounds().height / 2);
	}

	~Item()
	{
	}

	bool use() {
		//Usage requirements
		if (usage > 0) {
			usage--;
			return true;
		}

		return false;
	}

	void setPositionSprite(float x, float y) {
		Itemsprite.setPosition(x, y);
	}

	void setPositionText(float x, float y) {
		Itemdescription.setPosition(x, y);
		Amount.setPosition(x - 50, y);
	}

	void setPosition(float x, float y) {
		Itemsprite.setPosition(x, y);
		Itemdescription.setPosition(x+100, y);
		Amount.setPosition(x + Itemdescription.getLocalBounds().width + 150, y);
		Usebutton->setPosition(x + Itemdescription.getLocalBounds().width + Amount.getLocalBounds().width + 150, y);
	}

	void draw(sf::RenderWindow* window) {
		Amount.setString(std::to_string(usage));
		window->draw(Amount);
		window->draw(Itemsprite);
		window->draw(Itemdescription);
		Usebutton->draw(window);
	}
	bool check(sf::RenderWindow* window) {
		return Usebutton->check(window);
	}
};
