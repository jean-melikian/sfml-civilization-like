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

	sf::Text selectedText;
	bool hasSelection = false;
	std::vector<Unit *> units;
	SwordsmanUnit swordsman;
	units.push_back(&swordsman);

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

	sf::Vector2i clickPos;
	sf::Vector2f tmpPos;
	sf::Drawable *selected;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					clickPos = sf::Mouse::getPosition(window);
					for (int i = 0; i < units.size(); i++) {
						tmpPos = units[i]->getSprite().getPosition();
						if (tmpPos.x - clickPos.x < tileWidth
						    && tmpPos.y - clickPos.y < tileHeight) {
							selectedText = TextBuilder::Instance().build("SELECTED");
							selectedText.setPosition(tmpPos.x,
							                         tmpPos.y);
							hasSelection = true;
							break;
						}
					}
					break;
				default:
					break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				int randX = rand() % 3 + (-1);
				int randY = rand() % 3 + (-1);

				swordsman.move(randX, randY);
				sf::sleep(sf::milliseconds(100));
				hasSelection = false;
			}

			window.clear(sf::Color::Black);
			//window.draw(text);
			window.draw(map);
			window.draw(swordsman);
			if (hasSelection)
				window.draw(selectedText);
			window.display();
		}
	}

	return 0;
}