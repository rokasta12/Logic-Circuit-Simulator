#include "ORGate.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace orGateClass;

ORGate::ORGate(sf::RenderWindow* renderWindow) {
	cout << "andgate constructor" << endl;
	objectName = "OR";
	window = renderWindow;
	numPins = 3;
	string textureNames[] = { "OR" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);

}

void ORGate::calculateOutput() {
	cout << "or gate calculate" << endl;
	int pin0state = pins[0].getState();
	int pin1state = pins[1].getState();
	if (pin0state != pinClass::Pin::pinState::HIGHZ
		&&
		pin1state != pinClass::Pin::pinState::HIGHZ
		) {
		int calculatedOutputPinResult = pin0state + pin1state;
		if (calculatedOutputPinResult>=1) {
			pins[2].setState(pinClass::Pin::pinState::HIGH);
		}
		else {
			pins[2].setState(pinClass::Pin::pinState::LOW);
		}

	}

	directOutputPinResultToConnectedPins(2);
}