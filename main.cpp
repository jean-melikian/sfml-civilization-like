#include <iostream>
#include <SFML/Graphics.hpp>
#include "helpers/TextBuilder.hpp"
#include "entities/TileMap.hpp"
#include "models/SwordsmanUnit.hpp"

using namespace civ;

int main() {

	// on crée la fenêtre
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tilemap");
	window.setFramerateLimit(24);
	SwordsmanUnit swordsman;
	swordsman.load();


	// on définit le niveau à l'aide de numéro de tuiles
	const int level[] =
			{
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0,
					0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			};
	// on crée la tilemap avec le niveau précédemment défini
	TileMap map;
	if (!map.load("../assets/textures/medieval_tilesheet.png", sf::Vector2u(64, 64), level, civ::mapWidth,
	              civ::mapHeight))
		return -1;
	swordsman.setPosition(1, 1);

	sf::Text text = TextBuilder::Instance().build("Hit the space bar");
	text.setCharacterSize(32);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				int randX = rand() % 3 + (-1);
				int randY = rand() % 3 + (-1);

				swordsman.move(randX, randY);
				sf::sleep(sf::milliseconds(100));
			}

			window.clear(sf::Color::Black);
			//window.draw(text);
			window.draw(map);
			window.draw(swordsman);
			window.display();
		}
	}

	return 0;
}