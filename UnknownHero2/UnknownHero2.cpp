// "UnknownHero2.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <SFML\Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sfeMovie\Movie.hpp>
#include <list>
#include "player.h"
#include "button.h"
#include "Item.h"
#include "Userinterface.h"
#include "AnimatedSprite.h"



int main(){

	sfe::Movie Intro;
	if (!Intro.openFromFile("images/Gameintro.mp4")) {
		std::cout << "Coulnt load Intromovie" << std::endl;
	}



	//Initialize Window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Pokemon Battle", sf::Style::Close);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);


	//Load Font
	sf::Font pokemonfont;
	pokemonfont.loadFromFile("fonts/Pokemon Solid.ttf");

	sf::Font* pokemonfontptr;
	pokemonfontptr = &pokemonfont;

	//Initialize UI 
	UserInterface UI;

	//Load notpikatchu
	sf::Texture notPikatchuTexture;
	if (!notPikatchuTexture.loadFromFile("images/animation/notpikatchu.png"))
	{
		std::cout << "Failed to load notpikatchu spritesheet!" << std::endl;
		return 1;
	}

	Animation notPikatchuAnimation;

	notPikatchuAnimation.setSpriteSheet(notPikatchuTexture);
	notPikatchuAnimation.addFrame(sf::IntRect(64*0, 0, 64, 66));
	notPikatchuAnimation.addFrame(sf::IntRect(64*1, 0, 64, 66));
	notPikatchuAnimation.addFrame(sf::IntRect(64*2, 0, 64, 66));

	AnimatedSprite notPikatchuSprite(sf::seconds(0.33f), false, true);
	notPikatchuSprite.scale(2.5f,2.5f);
	notPikatchuSprite.setPosition(1100, 110);
	
	//Load notcharmander
	sf::Texture notCharmanderTexture;
	if (!notCharmanderTexture.loadFromFile("images/animation/notcharmander.png")) {
		std::cout << "Failed to load notcharmander spritesheet!" << std::endl;
		return 1;
	}

	Animation notCharmanderAnimation;

	notCharmanderAnimation.setSpriteSheet(notCharmanderTexture);
	notCharmanderAnimation.addFrame(sf::IntRect(64*0, 0, 64, 80));
	notCharmanderAnimation.addFrame(sf::IntRect(64*1, 0, 64, 80));
	notCharmanderAnimation.addFrame(sf::IntRect(64*2, 0, 64, 80));

	AnimatedSprite notCharmanderSprite(sf::seconds(0.33f), false, true);
	notCharmanderSprite.scale(2.5f, 2.5f);
	notCharmanderSprite.setPosition(1100, 110);


	//Load notBulbasaur
	sf::Texture notBulbasaurTexture;
	if (!notBulbasaurTexture.loadFromFile("images/animation/notbulbasaur.png")) {
		std::cout << "Failed to load notbulbasaur spritesheet!" << std::endl;
		return 1;
	}

	Animation notBulbasaurAnimation;

	notBulbasaurAnimation.setSpriteSheet(notBulbasaurTexture);
	notBulbasaurAnimation.addFrame(sf::IntRect(64 * 0, 0, 64, 80));
	notBulbasaurAnimation.addFrame(sf::IntRect(64 * 1, 0, 64, 80));
	notBulbasaurAnimation.addFrame(sf::IntRect(64 * 2, 0, 64, 80));

	AnimatedSprite notBulbasaurSprite(sf::seconds(0.33f), false, true);
	notBulbasaurSprite.scale(2.5f, 2.5f);
	notBulbasaurSprite.setPosition(1100, 120);

	//Load Doomguy
	sf::Texture Doomguytexture;
	if (!Doomguytexture.loadFromFile("images/animation/doomguy.png")) {
		std::cout << "Failed to load doomguy spritesheet!" << std::endl;
		return 1;
	}

	Animation DoomguyAnimation;

	DoomguyAnimation.setSpriteSheet(Doomguytexture);
	DoomguyAnimation.addFrame(sf::IntRect(32*0, 0, 32, 32));
	DoomguyAnimation.addFrame(sf::IntRect(32*1, 0, 32, 32));
	DoomguyAnimation.addFrame(sf::IntRect(32*2, 0, 32, 32));
	DoomguyAnimation.addFrame(sf::IntRect(32*3, 0, 32, 32));

	AnimatedSprite DoomguySprite(sf::seconds(0.33f), false, true);
	DoomguySprite.scale(8.0f,8.0f);
	DoomguySprite.setPosition(250, 344);

	//Load Platforms
	sf::Texture Platformstexture;
	if (!Platformstexture.loadFromFile("images/animation/grassanimation.png")) {
		std::cout << "Failed to load grassanimation spritesheet!" << std::endl;
		return 1;
	}

	Animation Platformsanimation;

	Platformsanimation.setSpriteSheet(Platformstexture);
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 0, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 1, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 2, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 3, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 4, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 5, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 6, 1600, 486));
	Platformsanimation.addFrame(sf::IntRect(0, 486 * 7, 1600, 486));

	AnimatedSprite Platformssprite(sf::seconds(0.2f),false,true);
	Platformssprite.setPosition(0.0f, 115.0f);


	

	//Initialize Player
	Player player(60,10,5,&DoomguyAnimation,&DoomguySprite);
	player.addItem(new Item("Healthpotion", pokemonfontptr, sf::Color::Red, "images/healthpotion.png", 5, &UI, 0));
	player.addItem(new Item("Weapon", pokemonfontptr, sf::Color::Black, "images/weapon.png", 5, &UI, 1));
	player.addItem(new Item("Shield", pokemonfontptr, sf::Color::Blue, "images/shield.png", 5, &UI, 2));

	//Initialize Enemy array
	Player* Enemies[3];
	int Anzahl_Gegner = 3;

	//Initialize Enemies
	Player enemie_notpikatchu(50, 10, 5,&notPikatchuAnimation,&notPikatchuSprite);
	enemie_notpikatchu.addItem(new Item("Golden Cup", pokemonfontptr, sf::Color::Black, "images/healthpotion.png", 5, &UI, 0));
	Enemies[0] = &enemie_notpikatchu;

	Player enemie_notCharmander(60, 10, 5, &notCharmanderAnimation, &notCharmanderSprite);
	enemie_notCharmander.addItem(new Item("Golden Cup", pokemonfontptr, sf::Color::Black, "images/healthpotion.png", 10, &UI, 0));
	Enemies[1] = &enemie_notCharmander;

	Player enemie_notBulbasaur(70, 10, 5, &notBulbasaurAnimation, &notBulbasaurSprite);
	enemie_notBulbasaur.addItem(new Item("Golden Cup", pokemonfontptr, sf::Color::Black, "images/healthpotion.png", 15, &UI, 0));
	Enemies[2] = &enemie_notBulbasaur;




	//Initialize Text
	std::list<sf::Text*> Sidetext;

	//Initialize Buttons
	button angriffbutton(100.0f, 680.0f, &UI, "images/button_green.png", "images/button_red.png");
	button itembutton(100.0f, 780.0f, &UI, "images/button_green.png", "images/button_red.png");
	button itembackbutton(200.0f, 780.0f, &UI, "images/button_green.png", "images/button_red.png");

	button closebutton(800.0f, 700.0f, &UI, "images/close.png", "images/close.png");
	closebutton.scale(10.0f, 10.0f);

	//button optionbutton(800.0f, 500.0f, &UI, "images/option.png", "images/option.png");
	//optionbutton.scale(10.0f, 10.0f);

	button startbutton(800.0f, 300.0f, &UI, "images/start.png", "images/start.png");
	startbutton.scale(10.0f, 10.0f);

	bool sideswitch = true;
	int uiswitch = 3; // 0 = Game , 1 = Itemui, 2 = mainmenu, 3 = Intro

	sf::Clock frameclock;
	sf::Clock Waittime;

	//set first enemie
	int enemiecounter = 0;
	Player* currentEnemie = Enemies[enemiecounter];

	//Initialize Music array
	sf::Music* Battlemusics[3];

	//Initialize Music
	sf::Music Maintheme;
	if (!Maintheme.openFromFile("music/main_theme.ogg")) {
		std::cout << "failed to load main theme" << std::endl;
	}
	Maintheme.setVolume(40);

	sf::Music Itemmusic;
	if (!Itemmusic.openFromFile("music/Cool Struttin'.ogg") ){
		std::cout << "failed to load Item music" << std::endl;
	}
	Itemmusic.setVolume(40);

	//Initialize Battlethemes

	sf::Music notPikatchu_Battletheme;
	if (!notPikatchu_Battletheme.openFromFile("music/jlbrock44_-_Reusenoise_(DNB_Mix)_1.ogg")) {
		std::cout << "failed to load notpikatchu battle theme" << std::endl;
	}
	notPikatchu_Battletheme.setVolume(40);
	Battlemusics[0] = &notPikatchu_Battletheme;

	sf::Music notCharmander_Battletheme;
	if (!notCharmander_Battletheme.openFromFile("music/7OOP3D_-_Feeling_Dark_(Behind_The_Mask).ogg")) {
		std::cout << "failed to load notcharmander battle theme" << std::endl;
	}
	notCharmander_Battletheme.setVolume(40);
	Battlemusics[1] = &notCharmander_Battletheme;

	sf::Music notBulbasaue_Battletheme;
	if (!notBulbasaue_Battletheme.openFromFile("music/battle_theme.ogg")) {
		std::cout << "failed to load notbulbasaur battle theme" << std::endl;
	}
	notBulbasaue_Battletheme.setVolume(40);
	Battlemusics[2] = &notBulbasaue_Battletheme;

	sf::Music* currentBattleMusic = Battlemusics[enemiecounter];

	
	Intro.play();

	while (window.isOpen())
	{
		currentBattleMusic->pause();
		Itemmusic.pause();
		//Close window if x button is pressed
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				//Do Cleanup
				window.close();
			}
		}

		//if player is defeated
		if (player.getcurrentHealth() <= 0) {
			//losescreen
			//uiswitch = 4;
		}

		//If the enemy is defeated
		if (currentEnemie->getcurrentHealth() <= 0) {
			//reset
			player.setcurrentHealth(player.getMaxHealth());
			
			//queue next enemie;
			enemiecounter++;
			if (enemiecounter > Anzahl_Gegner-1) {
				//Winscreen
				//uiswitch = 5;
			}
			currentBattleMusic = Battlemusics[enemiecounter];
			currentEnemie = Enemies[enemiecounter];

			UI.updateHealthbar(&player);
			UI.updateEnemieHealthBar(currentEnemie);
		}

		if (uiswitch == 0) {
			currentBattleMusic->play();

			currentEnemie->getSprite()->play(*(currentEnemie->getAnimation()));
			player.getSprite()->play(*(player.getAnimation()));
			Platformssprite.play(Platformsanimation);

			if (sideswitch) {
				//check buttons
				if (angriffbutton.check(&window)) {
					int schaden = (currentEnemie->defense - rand() % currentEnemie->defense) - player.attack;
					currentEnemie->setcurrentHealth(currentEnemie->getcurrentHealth() + schaden);
					UI.updateEnemieHealthBar(currentEnemie);

					std::string angriffstext;
					angriffstext = "Spieler greift an und macht ";
					angriffstext += std::to_string(std::abs(schaden));
					angriffstext += " Schaden";
					sf::Text* text = new sf::Text(angriffstext, pokemonfont, 24);
					text->setFillColor(sf::Color::White);
					text->setOutlineColor(sf::Color::Red);
					text->setOutlineThickness(2.0f);
					Sidetext.push_front(text);

					sideswitch = false;
					Waittime.restart();
				}
				if (itembutton.check(&window)) {
					uiswitch = 1;
				}
			}
			else {
				//Gegneraktion //AI
				
				if (Waittime.getElapsedTime() > sf::seconds(1)) {
					Waittime.restart();
					srand(time(NULL));
					int random = rand() % 10;

					//Healing
					switch (random) {
					case 9:
						if (!(currentEnemie->getcurrentHealth() == currentEnemie->getMaxHealth())) {
							int heilung = 5 + rand() % currentEnemie->getcurrentHealth();
							currentEnemie->setcurrentHealth(currentEnemie->getcurrentHealth() + heilung);
							UI.updateEnemieHealthBar(currentEnemie);

							std::string heiltext;
							heiltext = "Gegner heilt sich um ";
							heiltext += std::to_string(std::abs(heilung));
							heiltext += " Punkte";

							sf::Text* text = new sf::Text(heiltext, pokemonfont, 24);
							text->setFillColor(sf::Color::Red);
							text->setOutlineColor(sf::Color::White);
							text->setOutlineThickness(2.0f);
							Sidetext.push_front(text);
							sideswitch = true;
							break;
						}
					default:
						//Attack
						int schaden = (player.defense - rand() % player.defense/2) - currentEnemie->attack;
						
						player.setcurrentHealth(player.getcurrentHealth() - (std::abs(schaden)));
						UI.updateHealthbar(&player);

						std::string angriffstext;
						angriffstext = "Gegner greift an und macht ";
						angriffstext += std::to_string(std::abs(schaden));
						angriffstext += " Schaden";
						sf::Text* text = new sf::Text(angriffstext, pokemonfont, 24);
						text->setFillColor(sf::Color::Red);
						text->setOutlineColor(sf::Color::White);
						text->setOutlineThickness(2.0f);
						Sidetext.push_front(text);
						sideswitch = true;
						break;
					}
				
					
				}
			}
			sf::Time FrameTime = frameclock.restart();
			currentEnemie->getSprite()->update(FrameTime);
			player.getSprite()->update(FrameTime);
			Platformssprite.update(FrameTime);

			window.clear();
			//Draw everything here:
			window.draw(Platformssprite);
			window.draw(*player.getSprite());
			window.draw(*currentEnemie->getSprite());
			UI.draw(&window, uiswitch);
			angriffbutton.draw(&window);
			itembutton.draw(&window);
			int i = 0, x = 700, y = 700;
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
			Itemmusic.play();
			//check for back-button
			if (itembackbutton.check(&window)) {
				uiswitch = 0;
			}
			//check for Itembutton
			//with all items
			for (unsigned int i=0; i < 3;i++)
			{
				//check if your button was clicked
				if (player.getItems()[i]->check(&window)) {
					//and if the use requirements are set
					if (player.getItems()[i]->use()) {
						if (player.getItems()[i]->itemtype == 0) {
							//do healthitem stuff
							if (!(player.getcurrentHealth() == player.getMaxHealth())) {
								int heilung = 10 + rand() % player.getcurrentHealth();
								player.setcurrentHealth(player.getcurrentHealth() + heilung);
								UI.updateHealthbar(&player);

								std::string heiltext;
								heiltext = "Spieler heilt sich um ";
								heiltext += std::to_string(std::abs(heilung));
								heiltext += " Punkte";

								sf::Text* text = new sf::Text(heiltext, pokemonfont, 24);
								text->setFillColor(sf::Color::White);
								Sidetext.push_front(text);

								uiswitch = 0;
								sideswitch = false;
							}
							else {
								sf::Text* text = new sf::Text("Lebenspunte sind bereits voll!", pokemonfont, 24);
								text->setFillColor(sf::Color::White);
								Sidetext.push_front(text);

								uiswitch = 0;
								
							}
														
						}
						if (player.getItems()[i]->itemtype == 1) {
							//do attackitem stuff
							int attacke = 50 / player.attack;
							player.attack = player.attack + attacke;

							std::string attacktext;
							attacktext = "Spieler erhoeht seine Attacke um ";
							attacktext += std::to_string(std::abs(attacke));
							attacktext += " Punkte";

							sf::Text* text = new sf::Text(attacktext, pokemonfont, 24);
							text->setFillColor(sf::Color::White);
							Sidetext.push_front(text);

							uiswitch = 0;
							sideswitch = false;
						}
						if (player.getItems()[i]->itemtype == 2) {
							//do defenseitem stuff
							int defense = player.defense;
							player.defense++;

							std::string defensetext;
							defensetext = "Spieler erhoeht seine Verteidung um ";
							defensetext += std::to_string(std::abs(player.defense - defense));
							defensetext += " Punkte";

							sf::Text* text = new sf::Text(defensetext, pokemonfont, 24);
							text->setFillColor(sf::Color::White);
							Sidetext.push_front(text);

							uiswitch = 0;
							sideswitch = false;
						}
					}
				}
			}
			//set position of Items
			int y = 100;
			int sizeofitems = player.getItems().size();
			for (unsigned int i = 0; i < 3; i++)
			{
				player.getItems()[i]->setPosition(100, y);
				y = y + 110;
			}

			window.clear();
			//draw
			UI.draw(&window, uiswitch);
			itembackbutton.draw(&window);
			for (unsigned int i = 0; i< 3; i++)
			{
				player.getItems()[i]->draw(&window);
			}
			window.display();
		}
		if (uiswitch == 2) {

			if (startbutton.check(&window)) {
				uiswitch = 0;
			}
			//if (optionbutton.check(&window)) {
			//	uiswitch = 3;
			//}
			if (closebutton.check(&window)) {
				//Cleanup
				window.close();
			}

			window.clear();
			UI.draw(&window, uiswitch);
			startbutton.draw(&window);
			//optionbutton.draw(&window);
			closebutton.draw(&window);
			window.display();
		}
		if (uiswitch == 3) {
			Intro.update();

			if (Intro.getStatus() == sfe::Status::Stopped) {
				uiswitch = 3;
			}
			
			window.clear();
			window.draw(Intro);
			window.display();
		}
	}

	return 0;
}

