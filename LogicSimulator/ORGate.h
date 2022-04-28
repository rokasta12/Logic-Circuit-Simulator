#pragma once
#include "LogicElement.h"

namespace orGateClass {

	class ORGate :public logicElementClass::LogicElement {
	public:
		ORGate(sf::RenderWindow*);
		void calculateOutput();
	};
}

