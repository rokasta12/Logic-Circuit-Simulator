#include "XorGate.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace xorGateClass;

XorGate::XorGate(sf::RenderWindow* renderWindow) {
	objectName = "XOR";
	window = renderWindow;
	numPins = 3;
	string textureNames[] = { "XOR" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
	
}

void XorGate::calculateOutput() {
	int pin0state = pins[0].getState();
	int pin1state = pins[1].getState();
	if (pin0state != pinClass::Pin::pinState::HIGHZ
		&&
		pin1state != pinClass::Pin::pinState::HIGHZ
		) {
		if(pin0state != pin1state){
			pins[2].setState(pinClass::Pin::pinState::HIGH);
		}else {
			pins[2].setState(pinClass::Pin::pinState::LOW);
		}
	}

	directOutputPinResultToConnectedPins(2);
}