#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"

namespace wire {
	class Wire:public objectclass::Object{
		protected:
			sf::Vertex line[2];
			pinClass::Pin* pins[2];
		public:
			Wire(float,float, sf::RenderWindow*, pinClass::Pin*);
		
			void setLineVertice(float, float);
			void setPointerOfSecondPin(pinClass::Pin*);

			void drawObjectToWindow();

			bool isPinTwoNullPointer();

			pinClass::Pin* getWirePinsPtrByIndex(int);

			sf::Vector2f getWireLineByIndex(int);
	};

	
}


