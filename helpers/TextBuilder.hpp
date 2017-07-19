//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#ifndef MY_CIVILIZATION_TEXTBUILDER_H
#define MY_CIVILIZATION_TEXTBUILDER_H

namespace civ {

	class TextBuilder {
	public:
		static TextBuilder &Instance();

		TextBuilder(TextBuilder const &) = delete; // copy constructor
		TextBuilder(TextBuilder &&) = delete;// move constructor
		TextBuilder &operator=(TextBuilder const &) = delete; // copy assign
		TextBuilder &operator=(TextBuilder &&) = delete; // move assign

	protected:
		sf::Font defaultFont;
		unsigned int defaultSize = 12;
		std::string defaultFontPath = "../assets/fonts/kenpixel_mini_square.ttf";

	public:
		sf::Text build(std::string string);

		TextBuilder();

		~TextBuilder();
	};
}


#endif //MY_CIVILIZATION_TEXTBUILDER_H
