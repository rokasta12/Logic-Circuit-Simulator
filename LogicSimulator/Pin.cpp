#include<iostream>
#include "Pin.h"
using namespace pinClass;
using namespace std;

Pin::Pin() {
	cout << "pin default const" << endl;
	state = Pin::pinState::HIGHZ;
	numOfConnections = 0;
/*	for (int i = 0; i < 9; i++) {
		Pin* asd;
		connectedTo[i] =  asd;
	}*/
}

void Pin::setPinPosition(float x,float y) {
	pinPosition = sf::Vector2f(x, y);
}
void Pin::setPinIndex(int index) {
	pinIndex = index;
}

sf::Vector2f Pin::getPinPosition() {
	return pinPosition;
}

void Pin::setType(Pin::pinType pintype){
	type = pintype;
}

int Pin::getType(){
	return type;
}

void Pin::setState(Pin::pinState pinstate){
	if (this) {
		state = pinstate;
	}
}

int Pin::getState(){
	return state;
}

void Pin::setNumOfConnections(bool query){
	if (query) {
		numOfConnections = numOfConnections + 1;
	}
	else if(numOfConnections>0) {
		numOfConnections = numOfConnections - 1;
	}
}

int Pin::getNumOfConnections() {
	return numOfConnections;
}

Pin* Pin::getConnectedToSinglePtr(int index) {
	return connectedTo[index];
}

void Pin::setConnectedToByIndex(Pin* pinptr,int index){
	connectedTo[index] = pinptr;
}

void Pin::setConnectedToNullptr(Pin* deletePtr) {
	for (int i = 0; i < 9; i++) {
		Pin* isSamePtr = connectedTo[i];
		if (isSamePtr && (isSamePtr==deletePtr)) {
			connectedTo[i] = nullptr;
		}
	}
}