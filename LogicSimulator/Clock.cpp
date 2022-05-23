#include "Clock.h"
#include <iostream>
#include <string>
#include "Pin.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace clockClass;

Clock::Clock(sf::RenderWindow* renderWindow) {
<<<<<<< HEAD
=======
	cout << "CLOCK constructor" << endl;
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
	objectName = "CLOCK";
	window = renderWindow;
	numPins = 1;
	string textureNames[] = { "CLOCK" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
}

void Clock::calculateOutput() {
<<<<<<< HEAD
	sf::Time elapsedTime;
	elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() > 1) {
		int outputPinState=pins[0].getState();
		if (outputPinState) {
			cout << "sifir oldu" << endl;
			pins[0].setState(pinClass::Pin::pinState::LOW);
		}
		else {
			cout << "bir oldu" << endl;
=======
	cout << "clock calculate" << endl;
	sf::Time elapsedTime;
	elapsedTime = clock.getElapsedTime();
	cout << elapsedTime.asSeconds() << endl;
	if (elapsedTime.asSeconds() > 1) {
		int outputPinState=pins[0].getState();
		if (outputPinState) {
			pins[0].setState(pinClass::Pin::pinState::LOW);
		}
		else {
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
			pins[0].setState(pinClass::Pin::pinState::HIGH);
		}
		directOutputPinResultToConnectedPins(0);
		clock.restart();
<<<<<<< HEAD
=======
		cout << "koydu restarti"<< endl;;
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
	}




}