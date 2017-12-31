// "UnknownHero2.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "UserInteface.h"
#include "button.h"
#include "player.h"

int main()
{
	//Initialize Window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pokemon Battle", sf::Style::Close);
	UserInterface UI;
	Player player(100);
	Player enemie(100);
	button angriffbutton(100.0f, 680.0f, &UI, &enemie);
	button itembutton(100.0f, 780.0f, &UI, &enemie);
	button itembackbutton(200.0f, 780.0f, &UI, &enemie);
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

		if (uiswitch == 0) {
			if (sideswitch) {
				//check buuttons
				if (angriffbutton.check(&window)) {
					enemie.setcurrentHealth(enemie.getcurrentHealth() - 10);
					UI.updateEnemieHealthBar(&enemie);
					sideswitch = false;
				}
				if (itembutton.check(&window)) {
					uiswitch = 1;
				}
			}
			else {
				//Gegneraktion //AI

				sideswitch = true;
			}

			window.clear();
			//Draw everything here:
			UI.draw(&window, 0);
			angriffbutton.draw(&window);
			itembutton.draw(&window);
			window.display();
		}
		if (uiswitch == 1) {
			if (itembackbutton.check(&window)) {
				uiswitch = 0;
			}
			window.clear();
			//draw
			UI.draw(&window, 1);
			itembackbutton.draw(&window);
			window.display();
		}
		if (uiswitch == 2) {
			window.clear();
			window.display();
		}
	}

	return 0;
}