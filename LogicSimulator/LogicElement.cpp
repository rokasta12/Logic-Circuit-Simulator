#include <iostream>
#include <SFML/Graphics.hpp>
#include "LogicElement.h"
#include "Pin.h"

using namespace std;
using namespace logicElementClass;

LogicElement::LogicElement() {
	cout << "logic element class constructor" << endl;
}

void LogicElement::setPins(){
	sf::Vector2f spritePosition = sprite.getPosition();
	float x = spritePosition.x;
	float y = spritePosition.y;
	cout << "sprite pos" << x << " " << y << endl;
	switch (numPins)
	{
		case 1:
			if (objectName == "GND") {
				pins[0].setPinPosition(pinPos::gndI1x+x, pinPos::gndI1y+y);
				pins[0].setType(pinClass::Pin::pinType::OUTPUT);
				pins[0].setState(pinClass::Pin::pinState::LOW);
			}else if(objectName == "LED"){
				pins[0].setPinPosition(pinPos::ledI1x+x, pinPos::ledI1y+y);
				pins[0].setType(pinClass::Pin::pinType::INPUT);
				pins[0].setState(pinClass::Pin::pinState::HIGHZ);
			}
			else if (objectName == "CLOCK") {
				pins[0].setPinPosition(pinPos::clockI1x+x, pinPos::clockI1y+y);
				pins[0].setType(pinClass::Pin::pinType::OUTPUT);
				pins[0].setState(pinClass::Pin::pinState::HIGH); //clock highdan basliyor
			}
			else if (objectName == "VDD") {
				pins[0].setPinPosition(pinPos::vddI1x+x, pinPos::vddI1y+y);
				pins[0].setType(pinClass::Pin::pinType::OUTPUT);
				pins[0].setState(pinClass::Pin::pinState::HIGH);
			}
			pins[0].setPinIndex(0);
			break;
		case 2:
			pins[0].setPinPosition(pinPos::notI1x+x, pinPos::notI1y+y);
			pins[1].setPinPosition(pinPos::notO1x+x, pinPos::notO1y+y);
			pins[0].setType(pinClass::Pin::pinType::INPUT);
			pins[1].setType(pinClass::Pin::pinType::OUTPUT);
			pins[0].setPinIndex(0);
			pins[1].setPinIndex(1);
			pins[0].setState(pinClass::Pin::pinState::HIGHZ);
			pins[1].setState(pinClass::Pin::pinState::HIGHZ);
			break;
		case 3:
			pins[0].setPinPosition(pinPos::threePinI1x+x, pinPos::threePinI1y+y);
			pins[1].setPinPosition(pinPos::threePinI2x+x, pinPos::threePinI2y+y);
			pins[2].setPinPosition(pinPos::threePinO1x+x, pinPos::threePinO1y+y);
			pins[0].setType(pinClass::Pin::pinType::INPUT);
			pins[1].setType(pinClass::Pin::pinType::INPUT);
			pins[2].setType(pinClass::Pin::pinType::OUTPUT);
			pins[0].setPinIndex(0);
			pins[1].setPinIndex(1);
			pins[2].setPinIndex(2);
			pins[0].setState(pinClass::Pin::pinState::HIGHZ);
			pins[1].setState(pinClass::Pin::pinState::HIGHZ);
			pins[2].setState(pinClass::Pin::pinState::HIGHZ);	
			break;
		case 4:
			pins[0].setPinPosition(pinPos::dffI1x+x, pinPos::dffI1y+y);
			pins[1].setPinPosition(pinPos::dffI2x+x, pinPos::dffI2y+y);
			pins[2].setPinPosition(pinPos::dffO1x+x, pinPos::dffO1y+y);
			pins[3].setPinPosition(pinPos::dffO2x+x, pinPos::dffO2y+y);
			pins[0].setType(pinClass::Pin::pinType::INPUT);
			pins[1].setType(pinClass::Pin::pinType::INPUT);
			pins[2].setType(pinClass::Pin::pinType::OUTPUT);
			pins[3].setType(pinClass::Pin::pinType::OUTPUT);
			pins[0].setPinIndex(0);
			pins[1].setPinIndex(1);
			pins[2].setPinIndex(2);
			pins[3].setPinIndex(3);
			pins[0].setState(pinClass::Pin::pinState::HIGHZ);
			pins[1].setState(pinClass::Pin::pinState::HIGHZ);
			pins[2].setState(pinClass::Pin::pinState::HIGHZ);
			pins[3].setState(pinClass::Pin::pinState::HIGHZ);
			break;
		default:
			cout << "pins are set" << endl;
			break;
	}
}

pinClass::Pin* LogicElement::getPinsByIndex(int index) {
	return &pins[index];
}

void LogicElement::calculateOutput() {};


void LogicElement::directOutputPinResultToConnectedPins(int index) {
	int outputPinState = pins[index].getState();
	if (outputPinState != pinClass::Pin::pinState::HIGHZ) {
		int numOfConnections = pins[index].getNumOfConnections();
		for (int i = 0; i < numOfConnections; i++) {
			pinClass::Pin* pinPtr = pins[index].getConnectedToSinglePtr(i);
			switch (outputPinState)
			{
			case pinClass::Pin::pinState::HIGH:
				pinPtr->setState(pinClass::Pin::pinState::HIGH);
				break;
			case pinClass::Pin::pinState::LOW:
				pinPtr->setState(pinClass::Pin::pinState::LOW);
				break;
			}
		}
	}
}

int LogicElement::getNumPins() {
	return numPins;
}