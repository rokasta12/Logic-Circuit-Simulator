#include<iostream>
#include "Pin.h"
#include "Object.h"

using namespace pinClass;
using namespace std;

Pin::Pin() {
	cout << "pin default const" << endl;
	state = Pin::pinState::HIGHZ;
	numOfConnections = 0;
	for (int i = 0; i < 10; i++) {
		
		wires[i] = nullptr;
	}
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

void Pin::setWiresByIndex(objectclass::Object* objectWirePtr,int index) {
	wires[index] = objectWirePtr;
}

objectclass::Object* Pin::getWiresByIndex(int index){
	return wires[index];
}

void Pin::setWiresNullptr(objectclass::Object* deletePtr) {
	for (int i = 0; i < 9; i++) {
		objectclass::Object* isSamePtr = wires[i];
		if (isSamePtr && (isSamePtr == deletePtr)) {
			wires[i] = nullptr;
		}
	}
}