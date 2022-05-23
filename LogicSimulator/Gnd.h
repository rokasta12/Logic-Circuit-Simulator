#pragma once
#include "LogicElement.h"

namespace gnd {

	class Gnd:public logicElementClass::LogicElement {
	public:
		Gnd(sf::RenderWindow*);
		void calculateOutput();
	};
}

