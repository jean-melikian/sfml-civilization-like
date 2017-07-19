//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include "TextBuilder.hpp"

namespace civ {

	TextBuilder &TextBuilder::Instance() {
		static TextBuilder instance;
		return instance;
	}

	TextBuilder::TextBuilder() {
		defaultFont.loadFromFile(defaultFontPath);

		std::cout << "TextBuilder instance created" << std::endl;

	}

	TextBuilder::~TextBuilder() {
		std::cout << "TextBuilder instance destructed" << std::endl;
	}

	sf::Text TextBuilder::build(std::string string) {
		sf::Text text(string, defaultFont, defaultSize);

		return text;
	}
}