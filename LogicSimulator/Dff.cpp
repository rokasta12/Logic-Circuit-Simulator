#include "Dff.h"
#include <iostream>
#include <string>

using namespace std;
using namespace dff;

Dff::Dff(sf::RenderWindow* renderWindow) {
	cout << "DFF constructor" << endl;
	objectName = "DFF";
	window = renderWindow;
	numPins = 4;
	string textureNames[] = { "DFF" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
	
}

void Dff::calculateOutput() {
	cout << "dff calculate" << endl;
	int pin0state = pins[0].getState();
	int pin1state = pins[1].getState();
	if (pin0state != pinClass::Pin::pinState::HIGHZ
		&&
		pin1state != pinClass::Pin::pinState::HIGHZ
		) {
		if (pin1state == pinClass::Pin::pinState::HIGH) {
			if (pin0state) {
				pins[2].setState(pinClass::Pin::pinState::HIGH);
				pins[3].setState(pinClass::Pin::pinState::LOW);
			}
			else {
				pins[2].setState(pinClass::Pin::pinState::LOW);
				pins[3].setState(pinClass::Pin::pinState::HIGH);
			}
		}
	

	}

	directOutputPinResultToConnectedPins(2);
	directOutputPinResultToConnectedPins(3);
}