//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#ifndef MY_CIVILIZATION_UNIT_H
#define MY_CIVILIZATION_UNIT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "../helpers/Constants.hpp"

namespace civ {

	class Unit : public sf::Drawable, public sf::Transformable {
	protected:
		unsigned int healthPoints = 0;
		unsigned int attackPoints = 0;
		unsigned int attackRange = 0;

		static std::string filepath;

		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Unit();

		Unit(unsigned int healthPoints, unsigned int attackPoints, unsigned int attackRange);

		virtual bool load() = 0;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void setPosition(unsigned int x, unsigned int y);

		void move(int offsetX, int offsetY);

		const sf::Sprite &getSprite() const;

		unsigned int getHealthPoints() const;

		unsigned int getAttackPoints() const;

		unsigned int getAttackRange() const;
	};
}


#endif //MY_CIVILIZATION_UNIT_H
