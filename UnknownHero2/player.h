#pragma once
#include <SFML\Graphics.hpp>
class Player
{
private:
	int maxHealth, currentHealth;
	sf::Sprite playerSprite;
	sf::Texture texture;
public:

	Player(int maxHealth)
	{
		this->maxHealth = maxHealth;
		currentHealth = maxHealth;
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
