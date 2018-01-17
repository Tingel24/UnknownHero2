#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <SFML\Graphics.hpp>
#include <string>

class button;
class UserInterface;

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

	Item(std::string itemtext, sf::Font* font, sf::Color color, std::string itemtexturepath, int amount, UserInterface* UI, int itemtype);

	~Item()
	{
	}

	bool use();
	void setPositionSprite(float x, float y);
	void setPositionText(float x, float y);
	void setPosition(float x, float y);
	void draw(sf::RenderWindow* window);
	bool check(sf::RenderWindow* window);
	void addUsage(int UsageAmount);
	int getusage();
};
#endif