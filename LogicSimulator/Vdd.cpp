#include "Vdd.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace vdd;

Vdd::Vdd(sf::RenderWindow* renderWindow) {
	objectName = "VDD";
	window = renderWindow;
	numPins = 1;
	string textureNames[] = { "VDD" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);

}

void Vdd::calculateOutput() {
	int numOfConnections = pins[0].getNumOfConnections();
	for (int i = 0; i < numOfConnections; i++) {
		pinClass::Pin* pinPtr = pins[0].getConnectedToSinglePtr(i);
		pinPtr->setState(pinClass::Pin::pinState::HIGH);
	}
};