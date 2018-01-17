#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <list>

class Item;

class Player
{
private:
	int maxHealth;
	int currentHealth;

	sf::Sprite playerSprite;
	sf::Texture texture;

	std::vector<Item*> Items;

	Animation* animation;
	AnimatedSprite* animatedsprite;
public:
	int attack;
	int defense;

	Player(int maxHealth, int attack, int defense, Animation* animation,AnimatedSprite* animatedsprite)
	{

		this->maxHealth = maxHealth;
		this->currentHealth = maxHealth;

		this->animation = animation;
		this->animatedsprite = animatedsprite;

		this->attack = attack;
		this->defense = defense;

		Items.resize(3);
	}

	~Player()
	{
	}

	int getMaxHealth();
	int getcurrentHealth();
	void setcurrentHealth(int currentHealth);
	bool addItem(Item* newItem);
	Animation* getAnimation();
	AnimatedSprite* getSprite();
	Item* getItem(int itemtype);
	std::vector<Item*> getItems();
};
#endif

