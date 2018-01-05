#pragma once
#include <SFML\Graphics.hpp>
class Player
{
private:
	int maxHealth, currentHealth;
	
	sf::Sprite playerSprite;
	sf::Texture texture;
public:
	int attack;
	int defense;

	Player(int maxHealth,int attack,int defense)
	{
		this->maxHealth = maxHealth;
		currentHealth = maxHealth;

		this->attack = attack;
		this->defense = defense;
	}

	~Player()
	{
	}

	int getMaxHealth() {
		return maxHealth;
	}

	int getcurrentHealth() {
		return currentHealth;
	}

	void setcurrentHealth(int currentHealth) {
		this->currentHealth = currentHealth;
		if (this->currentHealth < 0) {
			this->currentHealth = 0;
		}
	}
};
