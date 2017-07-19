//
// Created by Jean-Christophe MELIKIAN on 18/07/2017.
//

#ifndef MY_CIVILIZATION_SWORDSMANUNIT_HPP
#define MY_CIVILIZATION_SWORDSMANUNIT_HPP

#include "Unit.hpp"

namespace civ {
	class SwordsmanUnit : public Unit {
	public:
		std::string filepath = assetsDir + "textures/medieval_unit_swordsman.png";

		SwordsmanUnit();

		bool load();

		bool load(std::string filepath);
	};
}


#endif //MY_CIVILIZATION_SWORDSMANUNIT_HPP
