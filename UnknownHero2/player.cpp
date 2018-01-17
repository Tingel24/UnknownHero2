#include "stdafx.h"
#include "player.h"
#include "Item.h"

int Player::getMaxHealth() {
	return maxHealth;
}

int Player::getcurrentHealth() {
	return currentHealth;
}

void Player::setcurrentHealth(int currentHealth) {
	this->currentHealth = currentHealth;
	if (this->currentHealth < 0) {
		this->currentHealth = 0;
	}
	if (this->currentHealth > this->maxHealth) {
		this->currentHealth = this->maxHealth;
	}
}

/*bool addItem(std::string itemtext, sf::Font* font, sf::Color color, std::string itemtexturepath, int amount, UserInterface* UI, int itemtype) {
if (!(itemtype == 0 || itemtype == 1 || itemtype == 2)) {
std::cout << "Wrong Itemtype, please use 0,1 or 2" << std::endl;
return false;
}
if (!(Items[itemtype] == NULL)) {
std::cout << "Entity already has Item of that type, adding Usageamount" << std::endl;
Items[itemtype]->addUsage(amount);
return true;
}
Items[itemtype] = new Item(itemtext, font, color, itemtexturepath, amount, UI, itemtype);
}*/

bool Player::addItem(Item* newItem) {
	if (!(newItem->itemtype == 0 || newItem->itemtype == 1 || newItem->itemtype == 2)) {
		std::cout << "Wrong Itemtype, please use 0,1 or 2" << std::endl;
		return false;
	}
	if (this->Items[newItem->itemtype] != NULL) {
		std::cout << "Entity already has Item of that type, adding Usageamount" << std::endl;
		this->Items[newItem->itemtype]->addUsage(newItem->getusage());
		return true;
	}
	std::vector<Item*>::iterator iterator1;
	iterator1 = Items.begin();
	this->Items.insert(iterator1+newItem->itemtype,newItem);
	return true;
};

Animation* Player::getAnimation() {
	return animation;
}

AnimatedSprite* Player::getSprite() {
	return animatedsprite;
}

Item* Player::getItem(int itemtype)
{
	if (!(itemtype == 0 || itemtype == 1 || itemtype == 2)) {
		std::cout << "Wrong Itemtype, please use 0,1 or 2" << std::endl;
		return NULL;
	}
	return Items[itemtype];

}
std::vector<Item*> Player::getItems() {
	return Items;
}