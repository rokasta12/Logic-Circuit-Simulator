#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

namespace pinClass {

	class Pin //MAX_CONNECTIONS=5
	{
	public:
		enum pinType { INPUT, OUTPUT };
		enum pinState { HIGHZ=2, LOW=0, HIGH=1 };
		protected:
			friend class Wire;
			friend class LogicElement;
		
			int pinIndex;
			pinType type;
			bool isSrc[10];

			Pin* connectedTo[10];
			objectclass::Object* wires[10]; //friend yapmadin
			int numOfConnections;
			sf::Vector2f pinPosition;
			pinState state;
		public:
			Pin();

			void setPinPosition(float,float);
			void setPinIndex(int);
			void setType(pinType);
			void setState(pinState);
			void setNumOfConnections(bool);
			void setConnectedToByIndex(Pin*,int);
			void setConnectedToNullptr(Pin*);

			int getType();
			int getState();
			int getNumOfConnections();
			sf::Vector2f getPinPosition();
			Pin* getConnectedToSinglePtr(int);

			
	};
}

