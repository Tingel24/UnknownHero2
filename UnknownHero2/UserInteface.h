#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"
class UserInterface
{
private:
	std::vector<sf::Sprite*> blocks;

	sf::Texture wood;
	sf::Texture wall;
	sf::Texture platform;
	sf::Texture green;

	sf::Sprite HealthBar;
	sf::Sprite HealthBarEnemy;

	sf::Font pokemonfont;
	sf::Text Attacktext;
	sf::Text Itemstext;

public:
	UserInterface() {
		//load images
		wood.loadFromFile("images/wood_floor.jpg");
		wall.loadFromFile("images/wall.jpg");
		platform.loadFromFile("images/platform.png");
		green.loadFromFile("images/green.png");

		//load text
		pokemonfont.loadFromFile("fonts/Pokemon Solid.ttf");

		Attacktext.setFont(pokemonfont);
		Itemstext.setFont(pokemonfont);

		Attacktext.setString("Angreifen");
		Itemstext.setString("Items");

		Attacktext.setCharacterSize(24);
		Itemstext.setCharacterSize(24);

		Attacktext.setPosition(200.0f, 680.0f);
		Itemstext.setPosition(200.0f, 780.0f);
		//create ui-elements
		for (size_t i = 0; i < 6; i++)
		{
			blocks.push_back(new sf::Sprite);
		}
		blocks[0]->setTexture(wall);
		blocks[0]->setTextureRect(sf::IntRect(0, 0, 1600, 300));
		blocks[0]->setPosition(0.0f, 600.0f);

		blocks[1]->setTexture(wood);
		blocks[1]->setTextureRect(sf::IntRect(0, 0, 1600, 25));
		blocks[1]->setPosition(0.0f, 600.0f);

		blocks[2]->setTexture(platform);
		blocks[2]->setTextureRect(sf::IntRect(0, 0, 1600, 500));
		blocks[2]->setPosition(0.0f, 100.0f);

		HealthBar.setTexture(green);
		HealthBar.setTextureRect(sf::IntRect(0, 0, 790, 100));
		HealthBar.setPosition(0.0f, 0.0f);

		HealthBarEnemy.setTexture(green);
		HealthBarEnemy.setTextureRect(sf::IntRect(0, 0, 790, 100));
		HealthBarEnemy.setPosition(820.0f, 0.0f);

		blocks[3]->setTexture(wall);
		blocks[3]->setTextureRect(sf::IntRect(0, 0, 1600, 900));
		blocks[3]->setPosition(0.0f, 0.0f);
	};
	~UserInterface() {};

	void draw(sf::RenderWindow *window, int uiswitch) {
		if (uiswitch == 0) {
			for (size_t i = 0; i < 3; i++)
			{
				window->draw(*blocks[i]);
			}

			window->draw(HealthBar);
			window->draw(HealthBarEnemy);
			window->draw(Attacktext);
			window->draw(Itemstext);
		}
		if (uiswitch == 1) {
			for (size_t i = 3; i < blocks.size(); i++)
			{
				window->draw(*blocks[i]);
			}
		}
		if (uiswitch == 2) {
		}
	}

	sf::Sprite* getHealthbar() {
		return &HealthBar;
	}

	sf::Sprite* getHealthbarEnemy() {
		return &HealthBarEnemy;
	}

	void updateHealthbar(Player* player) {
		HealthBar.setScale((float)(player->getcurrentHealth()) / player->getMaxHealth(), 1.0f);
	}

	void updateEnemieHealthBar(Player* player) {
		HealthBarEnemy.setScale(((float)(player->getcurrentHealth()) / player->getMaxHealth()), 1.0f);
	}
};
