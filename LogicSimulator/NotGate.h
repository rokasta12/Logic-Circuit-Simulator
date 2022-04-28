#pragma once
#include "LogicElement.h"

namespace notGateClass {

	class NotGate :public logicElementClass::LogicElement {
	public:
		NotGate(sf::RenderWindow*);
		void calculateOutput();
	};
}

