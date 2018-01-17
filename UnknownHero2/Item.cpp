#include "stdafx.h"
#include "Item.h"
#include "button.h"

Item::Item(std::string itemtext, sf::Font* font, sf::Color color, std::string itemtexturepath, int amount, UserInterface* UI, int itemtype)
{
	this->font = *font;
	usage = amount;
	this->itemtype = itemtype;

	Usebutton = new button(UI);

	Itemdescription.setFont(*font);
	Itemdescription.setString(itemtext);
	Itemdescription.setCharacterSize(24);
	Itemdescription.setFillColor(color);
	Itemdescription.setOutlineColor(sf::Color::White);
	Itemdescription.setOutlineThickness(2);
	Itemdescription.setOrigin(0, Itemdescription.getLocalBounds().height / 2);

	Amount.setFont(*font);
	Amount.setString(std::to_string(usage));
	Amount.setCharacterSize(24);
	Amount.setFillColor(color);
	Amount.setOutlineColor(sf::Color::White);
	Amount.setOutlineThickness(2);
	Amount.setOrigin(0, Amount.getLocalBounds().height / 2);

	Itemtexture.loadFromFile(itemtexturepath);
	Itemsprite.setTexture(Itemtexture);
	//Itemsprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	Itemsprite.setOrigin(Itemsprite.getLocalBounds().width / 2, Itemsprite.getLocalBounds().height / 2);
	Itemsprite.setScale(2, 2);
}

bool Item::use() {
	//Usage requirements
	if (usage > 0) {
		usage--;
		return true;
	}

	return false;
}

void Item::setPositionSprite(float x, float y) {
	Itemsprite.setPosition(x, y);
}

void Item::setPositionText(float x, float y) {
	Itemdescription.setPosition(x, y);
	Amount.setPosition(x - 50, y);
}

void Item::setPosition(float x, float y) {
	this->Itemsprite.setPosition(x, y);
	this->Itemdescription.setPosition(x + 100, y);
	this->Amount.setPosition(x + Itemdescription.getLocalBounds().width + 150, y);
	if(Itemdescription.getLocalBounds().width + Amount.getLocalBounds().width < 500){
		this->Usebutton->setPosition(x + 500, y);
	}
	else {
		this->Usebutton->setPosition(x + Itemdescription.getLocalBounds().width + Amount.getLocalBounds().width + 250, y);
	}
	
}

void Item::draw(sf::RenderWindow* window) {
	Amount.setString(std::to_string(usage));
	window->draw(Amount);
	window->draw(Itemsprite);
	window->draw(Itemdescription);
	Usebutton->draw(window);
}
bool Item::check(sf::RenderWindow* window) {
	return this->Usebutton->check(window);
}

void Item::addUsage(int UsageAmount) {
	this->usage = this->usage + UsageAmount;
}

int Item::getusage() {
	return this->usage;
}