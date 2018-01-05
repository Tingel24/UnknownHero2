// "UnknownHero2.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "UserInteface.h"
#include "button.h"
#include "player.h"
#include "Item.h"
#include <list>

int main()
{
	//Initialize Window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pokemon Battle", sf::Style::Close);

	sf::Font pokemonfont;
	pokemonfont.loadFromFile("fonts/Pokemon Solid.ttf");

	sf::Font* pokemonfontptr;
	pokemonfontptr = &pokemonfont;

	UserInterface UI;

	Player player(50,10,10);
	Player enemie(50,10,5);

	Item winitem("Golden Cupuscalusususu", pokemonfontptr, sf::Color::Black, "images/win.png",5,&UI,0);
	Item loseitem("Blue Cup", pokemonfontptr, sf::Color::Black, "images/win.png", 5,&UI,1);

	std::list<Item*> Items;
	Items.push_back(&winitem);
	Items.push_back(&loseitem);

	std::list<sf::Text*> Sidetext;

	button angriffbutton(100.0f, 680.0f, &UI);
	button itembutton(100.0f, 780.0f, &UI);
	button itembackbutton(200.0f, 780.0f, &UI);

	bool sideswitch = true;
	int uiswitch = 0; // 0 = UI, 1 = Itemui, 2 = mainmenu



	while (window.isOpen())
	{
		//Close window if x button is pressed
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				//Do Cleanup
				window.close();
			}
		}
		if (enemie.getcurrentHealth() <= 0) {
			//reset
			//queue next enemie;
			window.close();
		}

		if (uiswitch == 0) {
			if (sideswitch) {
				//check buttons
				if (angriffbutton.check(&window)) {
					int schaden = (enemie.defense - rand() % enemie.defense) - player.attack;
					enemie.setcurrentHealth(enemie.getcurrentHealth()+schaden);
					UI.updateEnemieHealthBar(&enemie);

					std::string angriffstext;
					angriffstext = "Spieler greift an und macht ";
					angriffstext += std::to_string(std::abs(schaden));
					angriffstext += " Schaden";
					sf::Text* text = new sf::Text(angriffstext, pokemonfont, 24);
					text->setFillColor(sf::Color::White);
					Sidetext.push_front(text);

					sideswitch = false;
				}
				if (itembutton.check(&window)) {
					uiswitch = 1;
				}
			}
			else {
				//Gegneraktion //AI
				sf::Clock Waittime;
				while (Waittime.getElapsedTime() < sf::seconds(1)) {};
				srand(time(NULL));
				int random = rand()%10;

				//Healing
				if (random >= 8) {
					if (!(enemie.getcurrentHealth() == enemie.getMaxHealth())) {
						int heilung = 5 + rand()%enemie.getMaxHealth();
						enemie.setcurrentHealth(enemie.getcurrentHealth() + heilung);
						UI.updateEnemieHealthBar(&enemie);

						std::string heiltext;
						heiltext = "Gegner heilt sich um ";
						heiltext += std::to_string(std::abs(heilung));
						heiltext += " Punkte";

						sf::Text* text = new sf::Text(heiltext, pokemonfont, 24);
						text->setFillColor(sf::Color::Red);
						Sidetext.push_front(text);
					}
				}
				else {
					//Attack

					int schaden = (player.defense - rand() % player.defense) - enemie.attack;
					player.setcurrentHealth(player.getcurrentHealth() + schaden);
					UI.updateHealthbar(&player);

					std::string angriffstext;
					angriffstext = "Gegner greift an und macht ";
					angriffstext += std::to_string(std::abs(schaden));
					angriffstext += " Schaden";
					sf::Text* text = new sf::Text(angriffstext, pokemonfont, 24);
					text->setFillColor(sf::Color::Red);
					Sidetext.push_front(text);
				}
				sideswitch = true;
			}

			window.clear();
			//Draw everything here:
			UI.draw(&window, uiswitch);
			angriffbutton.draw(&window);
			itembutton.draw(&window);
			int i = 0,x = 700, y = 700;
			for (auto element : Sidetext) {
				if (i < 10) {
					element->setPosition(x, y);
					y = y + 50;
					window.draw(*element);
				}
				i++;
			}
			window.display();
		}
		if (uiswitch == 1) {
			//check for back-button
			if (itembackbutton.check(&window)) {
				uiswitch = 0;
			}
			//check for Itembuttons
			for (auto element:Items)
			{
				if (element->check(&window)) {
					if (element->use()) {
						if (element->itemtype == 0) {
							//do healthitem stuff
						}
						if (element->itemtype == 1) {
							//do attackitem stuff
						}
						if (element->itemtype == 2) {
							//do defenseitem stuff
						}
					}
				}
			}
			//set position of Items
			int y = 100;
			for (auto element : Items)
			{
				element->setPosition(100, y);
				y = y + 110;
			}

			window.clear();
			//draw
			UI.draw(&window, uiswitch);
			itembackbutton.draw(&window);
			for (auto element:Items)
			{
				element->draw(&window);
			}
			window.display();
		}
		if (uiswitch == 2) {
			window.clear();
			UI.draw(&window, uiswitch);
			window.display();
		}
	}

	return 0;
}