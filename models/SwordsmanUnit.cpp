//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#include <iostream>
#include "SwordsmanUnit.hpp"

namespace civ {
	SwordsmanUnit::SwordsmanUnit() {
	}

	bool SwordsmanUnit::load() {
		return load(SwordsmanUnit::filepath);
	}

	bool SwordsmanUnit::load(std::string filepath) {
		if (!texture.loadFromFile(filepath)) {
			std::cout << "Failed to load the swordsman texture from " << filepath << std::endl;
			return false;
		}
		sprite.setTexture(texture);

		std::cout << "Loaded Swordsman !" << std::endl;
		sprite.setScale(tileWidth / sprite.getLocalBounds().width, tileHeight / sprite.getLocalBounds().height);
		return true;

	}

}