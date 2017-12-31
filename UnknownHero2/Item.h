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

	Item(std::string itemtext, sf::Font font, int stdCharsize)
	{
		this->font = font;

		Itemdescription.setFont(font);
		Itemdescription.setString(itemtext);
		Itemdescription.setCharacterSize(stdCharsize);
	}

	~Item()
	{
	}

	bool use() {
		return true;
	}
};
