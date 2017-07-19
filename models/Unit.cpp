//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#include <iostream>
#include "Unit.hpp"

namespace civ {
	Unit::Unit() {

	}

	Unit::Unit(unsigned int healthPoints, unsigned int attackPoints, unsigned int attackRange)
			: healthPoints(healthPoints), attackPoints(attackPoints), attackRange(attackRange) {

	}

	unsigned int Unit::getHealthPoints() const {
		return healthPoints;
	}

	unsigned int Unit::getAttackPoints() const {
		return attackPoints;
	}

	unsigned int Unit::getAttackRange() const {
		return attackRange;
	}

	void Unit::setPosition(unsigned int x, unsigned int y) {
		sprite.setPosition(x * tileWidth,
		                   y * tileHeight);
	}

	void Unit::move(int offsetX, int offsetY) {
		int x = offsetX * tileHeight;
		int y = offsetY * tileWidth;
		sprite.move((sprite.getPosition().x + x < 0 || windowWidth <= sprite.getPosition().x + x) ? 0 : x,
		            (sprite.getPosition().y + y < 0 || windowHeight <= sprite.getPosition().y + y) ? 0 : y);
		std::cout << "New position: " << sprite.getPosition().x << ";" << sprite.getPosition().y << std::endl;
	}


	const sf::Sprite &Unit::getSprite() const {
		return sprite;
	}

	void Unit::draw(sf::RenderTarget &target, sf::RenderStates states) const {
		// on applique la transformation
		states.transform *= getTransform();

		// on applique la texture du tileset
		states.texture = &texture;

		target.draw(sprite, states);

		std::cout << "Drawing unit" << std::endl;
	}

}