//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#ifndef MY_CIVILIZATION_TILEMAP_HPP
#define MY_CIVILIZATION_TILEMAP_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace civ {
	class TileMap : public sf::Drawable, public sf::Transformable {
	public:

		bool load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width,
		          unsigned int height);

	private:

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
	};

}
#endif //MY_CIVILIZATION_TILEMAP_HPP
