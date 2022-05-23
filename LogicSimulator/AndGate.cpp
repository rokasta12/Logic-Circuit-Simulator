#include <iostream>
#include "AndGate.h"
#include <string>
#include "Pin.h"

using namespace std;
using namespace andGateClass;

AndGate::AndGate(sf::RenderWindow *renderWindow) {
	objectName = "AND";
	window = renderWindow;
	numPins = 3;
	string textureNames[] = {"AND"};
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
}

void AndGate::calculateOutput() {
	int pin0state = pins[0].getState();
	int pin1state = pins[1].getState();
	if (pin0state != pinClass::Pin::pinState::HIGHZ
		&&
		pin1state != pinClass::Pin::pinState::HIGHZ
		) {
		int calculatedOutputPinResult = pin0state * pin1state;
		if (calculatedOutputPinResult) {
			pins[2].setState(pinClass::Pin::pinState::HIGH);
		}
		else {
			pins[2].setState(pinClass::Pin::pinState::LOW);
		}

	}

	directOutputPinResultToConnectedPins(2);
}