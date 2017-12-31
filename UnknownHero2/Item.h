#pragma once
#include <SFML\Graphics.hpp>
#include <string>
class Item
{
private:
	sf::Text Itemdescription;
	sf::Texture Itemtexture;
	sf::Sprite Itemsprite;
	sf::Font font;
public:

	Item(std::string itemtext, sf::Font* font, sf::Color color, std::string itemtexturepath)
	{
		this->font = *font;

		Itemdescription.setFont(*font);
		Itemdescription.setString(itemtext);
		Itemdescription.setCharacterSize(24);
		Itemdescription.setFillColor(color);

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

		return true;
	}

	void setPositionSprite(float x, float y) {
		Itemsprite.setPosition(x, y);
	}

	void setPositionText(float x, float y) {
		Itemdescription.setPosition(x, y);
	}

	void draw(sf::RenderWindow* window) {
		window->draw(Itemsprite);
		window->draw(Itemdescription);
	}
};
