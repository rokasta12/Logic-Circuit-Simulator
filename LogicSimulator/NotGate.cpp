#include "NotGate.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace notGateClass;

NotGate::NotGate(sf::RenderWindow* renderWindow) {
	objectName = "NOT";
	window = renderWindow;
	numPins = 2;
	string textureNames[] = { "NOT" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);

}

void NotGate::calculateOutput() {
	switch (pins[0].getState())
	{
		case pinClass::Pin::pinState::HIGHZ:
			break;
		case pinClass::Pin::pinState::HIGH:
			pins[1].setState(pinClass::Pin::pinState::LOW);
			break;
		case pinClass::Pin::pinState::LOW:
			pins[1].setState(pinClass::Pin::pinState::HIGH);
			break;
	}
	
	directOutputPinResultToConnectedPins(1);

}