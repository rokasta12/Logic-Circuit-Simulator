#include "Clock.h"
#include <iostream>
#include <string>
#include "Pin.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace clockClass;

Clock::Clock(sf::RenderWindow* renderWindow) {
	objectName = "CLOCK";
	window = renderWindow;
	numPins = 1;
	string textureNames[] = { "CLOCK" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
}

void Clock::calculateOutput() {
	cout << "clock calculate" << endl;
	sf::Time elapsedTime;
	elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() > 1) {
		int outputPinState=pins[0].getState();
		if (outputPinState) {
			pins[0].setState(pinClass::Pin::pinState::LOW);
		}
		else {
			pins[0].setState(pinClass::Pin::pinState::HIGH);
		}
		directOutputPinResultToConnectedPins(0);
		clock.restart();
	}




}