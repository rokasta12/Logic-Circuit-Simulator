#include "Gnd.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace gnd;

Gnd::Gnd(sf::RenderWindow* renderWindow) {
	cout << "ground constructor" << endl;
	objectName = "GND";
	window = renderWindow;
	numPins = 1;
	string textureNames[] = { "GND" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
	
}

//GIVE ALL CONNECTED PINS 0
void Gnd::calculateOutput() {
	int numOfConnections = pins[0].getNumOfConnections();
	for (int i = 0; i < numOfConnections; i++) {
		pinClass::Pin* pinPtr = pins[0].getConnectedToSinglePtr(i);
		pinPtr->setState(pinClass::Pin::pinState::LOW);
	}
	cout << "pins are set to 0" << endl;
}
