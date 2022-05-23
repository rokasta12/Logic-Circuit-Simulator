#pragma once
#include "LogicElement.h"

namespace vdd {

	class Vdd :public logicElementClass::LogicElement {
	public:
		Vdd(sf::RenderWindow*);
		void calculateOutput();
	};
}

