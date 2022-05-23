#pragma once
#include "LogicElement.h"

namespace andGateClass {

	class AndGate:public logicElementClass::LogicElement{
		public:
			AndGate(sf::RenderWindow *);
			void calculateOutput();
	};
}

