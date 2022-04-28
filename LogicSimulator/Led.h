#pragma once
#include "LogicElement.h"

namespace led {

	class Led :public logicElementClass::LogicElement {
	public:
		Led(sf::RenderWindow*);
		void calculateOutput();
	};
}

