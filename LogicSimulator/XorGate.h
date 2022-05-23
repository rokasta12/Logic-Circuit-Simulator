#pragma once
#include "LogicElement.h"

namespace xorGateClass {

	class XorGate :public logicElementClass::LogicElement {
	public:
		XorGate(sf::RenderWindow*);
		void calculateOutput();
	};
}

