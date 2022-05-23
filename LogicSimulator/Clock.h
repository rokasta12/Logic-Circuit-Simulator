#pragma once
#include "LogicElement.h"
#include <SFML/Graphics.hpp>

namespace clockClass {

	class Clock:public logicElementClass::LogicElement{
		protected:
			sf::Clock clock;
		public: 
		Clock(sf::RenderWindow*);
		void calculateOutput();
	};
}


