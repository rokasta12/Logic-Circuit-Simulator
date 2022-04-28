#include "Led.h"
#include <iostream>
#include <string>
#include "Pin.h"

using namespace std;
using namespace led;

Led::Led(sf::RenderWindow* renderWindow) {
	cout << "LED constructor" << endl;
	objectName = "LED";
	window = renderWindow;
	numPins = 1;
	string textureNames[] = { "LEDON","LEDOFF"};
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
	
}

void Led::calculateOutput() {
	cout << "led gate calculate" << endl;
	int pin0state = pins[0].getState();
	if (pin0state != pinClass::Pin::pinState::HIGHZ) {
		if (pin0state) {
			setSpriteTexture(0);
		}
		else {
			setSpriteTexture(1);
		}
	}
}
