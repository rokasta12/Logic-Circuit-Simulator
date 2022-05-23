#include "Wire.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pin.h"

using namespace wire;
using namespace std;

Wire::Wire(float x,float y, sf::RenderWindow* renderWindow,pinClass::Pin* ptr1) {
	objectName = "WIRE";
	locked = false;
	window = renderWindow;
	state = false;
	selected = false;

	pins[0] = ptr1;
	pins[1] = nullptr;
	line[0] = sf::Vector2f(x, y);
	line[1] = sf::Vector2f(x, y);
}


void Wire::setLineVertice(float x,float y){
	line[1] = sf::Vector2f(x, y);
}

void Wire::drawObjectToWindow() {
	if (selected) {//selectede göre renk ayarlayici if
		line[0].color = sf::Color(255, 0, 0, 255);
		line[1].color = sf::Color(255, 0, 0, 255);
	}
	else {
		line[0].color = sf::Color(255, 255, 255, 255);
		line[1].color = sf::Color(255, 255, 255, 255);
	}
	window->draw(line, 2, sf::Lines);
}

bool Wire::isPinTwoNullPointer() {
	if (pins[1] == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Wire::setPointerOfSecondPin(pinClass::Pin*ptr) {
	pins[1] = ptr;
}

pinClass::Pin* Wire::getWirePinsPtrByIndex(int index) {
	return pins[index];
}

sf::Vector2f Wire::getWireLineByIndex(int index){
	return line[index].position;
}