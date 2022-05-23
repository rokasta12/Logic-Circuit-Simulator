#include <iostream>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Simulator.h"
#include <string>
#include "Button.h"

#include "AndGate.h"
#include "ORGate.h"
#include "NotGate.h"
#include "Gnd.h"
#include "Dff.h"
#include "Vdd.h"
#include "XorGate.h"
#include "Led.h"
#include "Wire.h"
#include "Pin.h"
#include "Clock.h"
<<<<<<< HEAD
=======

>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
#include <cmath>
#include <math.h>
using namespace std;
using namespace simulatorClass;


Simulator::Simulator(sf::RenderWindow *renderWindow){
	window = renderWindow;
	headOfObjectList = 0;
	isSimulating = false;
<<<<<<< HEAD
	string items[] = {"OR","AND","XOR","NOT","GND","VDD","LED","DFF","CLOCK"};
	for (int i = 0; i < 9; i++) {
		createNewObject(items[i],10, 5+100*i, true);
=======
	cout << "default simulator constructor" << endl;
	string bumss[] = {"OR","AND","XOR","NOT","GND","VDD","LED","DFF","CLOCK"};
	for (int i = 0; i < 9; i++) {
		createNewObject(bumss[i],10, 5+100*i, true);

>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
	}
	createButtonToolBar();
}

void Simulator::appendObjectList(objectclass::Object *object){
	if (headOfObjectList) {
		objectclass::Object* tempPtr=NULL;
		tempPtr=headOfObjectList;
		while (tempPtr->getNext() != nullptr) {
			tempPtr = tempPtr->getNext();
		}
		tempPtr->setNext(object);
	}
	else {
		headOfObjectList = object;
	}
}

//return Object Pointer if a sprite clicked, otherwise return nullpointer
objectclass::Object* Simulator::getObjectPointerOfClicked(int mouseX,int mouseY) {
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		if(tempPtr->getGlobalBoundOfSprite().contains(mouseX,mouseY)){
			return tempPtr;
		}
		if (tempPtr->getObjectName() == "WIRE") {
			//calculate Right Angle Distance
			sf::Vector2f point0 = static_cast<wire::Wire*>(tempPtr)->getWireLineByIndex(0);
			sf::Vector2f point1 = static_cast<wire::Wire*>(tempPtr)->getWireLineByIndex(1);
			float p2xp1x = point1.x - point0.x;
			float p2yp1y = point1.y - point1.y;
			/*float p1ye0y = point1.y - mouseY;
			float p1xe0x = point1.x - mouseX;
			float distance = (abs(p2xp1x * p1ye0y - p1xe0x * p2yp1y)) / (sqrt(p2xp1x * p2xp1x + p2yp1y * p2yp1y));
			*/
			float A = sqrt(((point1.x - point0.x) * (point1.x - point0.x)) + ((point1.y - point0.y) * (point1.y - point0.y)));
			float B = sqrt(((mouseX - point1.x) * (mouseX - point1.x)) + ((mouseY - point1.y) * (mouseY - point1.y)));
			float C = sqrt(((point0.x - mouseX) * (point0.x - mouseX)) + ((point0.y - mouseY) * (point0.y - mouseY)));

			float side = ((A + B + C) / 2);
			// 2*area= dist*height
			float area = sqrt(side * (side - A) * (side - B) * (side - C));
			float distance = sqrt(p2xp1x * p2xp1x + p2yp1y * p2yp1y);
			float closenessToLine = (2 * area) / distance;
			if (closenessToLine < 10) {
				sf::FloatRect rect;
				if (point0.y > point1.y) {
					if (point0.x > point1.x) {
						rect=sf::FloatRect (point1.x-5, point1.y-5, point0.x-point1.x+10, point0.y-point1.y+10);
					}
					else {
						rect=sf::FloatRect (point0.x - 5, point1.y - 5, point1.x - point0.x + 10, point0.y - point1.y + 10);
					}
				}
				else {
					if (point0.x > point1.x) {
						rect=sf::FloatRect (point1.x - 5, point0.y - 5, point0.x - point1.x + 10, point1.y - point0.y + 10);
					}
					else {
						rect=sf::FloatRect (point0.x - 5, point0.y - 5, point1.x - point0.x + 10, point1.y - point0.y + 10);
					}
				}
				if (rect.contains(mouseX, mouseY)) {
					return tempPtr;
				}
			}
		}
		tempPtr = tempPtr->getNext();
	}

	return nullptr;
}

void::Simulator::resetSelectedOfObjects() {
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		tempPtr->setSelected(false);
		tempPtr = tempPtr->getNext();
	}
}

objectclass::Object* Simulator::getObjectPointerOfSelected() {
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		if (tempPtr->getSelected()==true) {
			return tempPtr;
		}
		tempPtr = tempPtr->getNext();
	}
	return nullptr;
}

//create new object according to objName
//After creation set its position and append the objec to the linked list
void Simulator::createNewObject(string objName, float posX, float posY,bool isLocked) {
	objectclass::Object* obptr = NULL;
	if (objName == "AND") {
		obptr = new andGateClass::AndGate(window);
	}else if (objName=="OR")
	{
		obptr = new orGateClass::ORGate(window);
	}else if (objName == "NOT")
	{
		obptr = new notGateClass::NotGate(window);
	}else if (objName == "DFF")
	{
		obptr = new dff::Dff(window);
	}else if (objName == "LED")
	{
		obptr = new led::Led(window);
	}else if (objName == "GND")
	{
		obptr = new gnd::Gnd(window);
	}else if (objName == "VDD")
	{
		obptr = new vdd::Vdd(window);
	}else if (objName == "XOR")
	{
		obptr = new xorGateClass::XorGate(window);
	}
	else if (objName == "CLOCK") {
		obptr = new clockClass::Clock(window);
	}

	if (obptr) {
		obptr->setSpritePosition(posX, posY);
		if (isLocked) {
			obptr->setLocked(isLocked);
			obptr->setLockedObjectPosition();
		}
		static_cast<logicElementClass::LogicElement*>(obptr)->setPins();
		appendObjectList(obptr);
	}
}

void Simulator::createButtonToolBar() {
	for (int i = 0; i < 2; i++) {
		objectclass::Object* obptr = NULL;
		obptr = new buttonClass::Button(i,window);
		obptr->setSpritePosition((220*(i+1))+50, 15);
		obptr->setLocked(true);
		appendObjectList(obptr);
	}
}

void Simulator::traverseAndDrawAllObjects() {
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		tempPtr->drawObjectToWindow();
		tempPtr = tempPtr->getNext();
	}
}


void Simulator::deleteObjectFromObjectList(objectclass::Object* deletePtr){
	objectclass::Object* currPtr = NULL;
	objectclass::Object* prevPtr = NULL;
	currPtr = headOfObjectList;
	while (currPtr != deletePtr) {
		prevPtr = currPtr;
		currPtr = currPtr->getNext();
	}
	if (currPtr->getNext()) {
		prevPtr->setNext(currPtr->getNext());
	}
	else {
		prevPtr->setNext(nullptr);
	}
	delete currPtr;
}

sf::Vector2f Simulator::getLockedObjectPositionByName(string objName){
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr  ) {
		if (tempPtr->getObjectName() == objName && tempPtr->getLocked() == true) {
			return tempPtr->getSprite().getPosition();
		}
		tempPtr = tempPtr->getNext();
	}
	return sf::Vector2f(0, 0);
}


void Simulator::createNewWire(float x,float y,pinClass::Pin* ptr1) {
	objectclass::Object* tempPtr = new wire::Wire(x,y,window,ptr1);
	appendObjectList(tempPtr);
}

// return being drawn wire object pointer by checking its second pin
objectclass::Object* Simulator::getWireObjectPointer(){
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		if (tempPtr->getObjectName() == "WIRE") {
			if (static_cast<wire::Wire*>(tempPtr)->isPinTwoNullPointer()) {
				return tempPtr;
			}
		}
		tempPtr = tempPtr->getNext();
	}
	return nullptr;
}


void Simulator::setIsDrawingWire(bool boolean) {
	isDrawingWire = boolean;
}
bool Simulator::getIsDrawingWire() {
	return isDrawingWire;
}

pinClass::Pin* Simulator::getPinPointerOfObj(objectclass::Object*eventObjPtr,float mouseX,float mouseY) {
	for (int i = 0; i < 4; i++) {
		pinClass::Pin* pinPointer = static_cast<logicElementClass::LogicElement*>(eventObjPtr)->getPinsByIndex(i);
		sf::Vector2f vect = pinPointer->getPinPosition();
		sf::FloatRect pinRect(vect.x, vect.y, 10, 10);
		if (pinRect.contains(mouseX,mouseY)) {
			return pinPointer;
		}
	}
	return nullptr;
}
pinClass::Pin* Simulator::traverseListAndGetPinPointerOfObj(float mouseX,float mouseY){
	objectclass::Object* tempPtr = NULL;
	tempPtr = headOfObjectList;
	while (tempPtr) {
		if (tempPtr->getObjectName() != "WIRE") {
			for (int i = 0; i < 3; i++) {
				pinClass::Pin* pinPointer = static_cast<logicElementClass::LogicElement*>(tempPtr)->getPinsByIndex(i);
				sf::Vector2f vect = pinPointer->getPinPosition();
				sf::FloatRect pinRect(vect.x, vect.y, 10, 10);
				if (pinRect.contains(mouseX, mouseY)) {
					return pinPointer;
				}
			}
		}
		tempPtr = tempPtr->getNext();
	}
	return nullptr;
}

bool Simulator::checkIfWireCanBeDrawn(pinClass::Pin *pinPtr,wire::Wire* wirePtr){
	if (!pinPtr) { //pin hedeflenmemisse
		return false;
	}
	pinClass::Pin* pinPtrOfFirstWirePin = wirePtr->getWirePinsPtrByIndex(0);
	if (pinPtr != pinPtrOfFirstWirePin ) { //ayni pin hedeflenmemisse
		if (pinPtr->getType() != pinPtrOfFirstWirePin->getType()) { //pinType'lar ayný degilse
			return true;
		}
	}
	return false;
}



//SIMULATION
void Simulator::startSimulation(){
	simulationClock.restart();
	sf::Time elapsedTime = simulationClock.getElapsedTime();
<<<<<<< HEAD
	while (isSimulating && elapsedTime.asSeconds() < 5) {
=======
	while (isSimulating && elapsedTime.asSeconds() < 4) {
		cout << "simulation start" << endl;
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
		objectclass::Object* tempPtr = NULL;
		tempPtr = headOfObjectList;
		while (tempPtr) {
			if (tempPtr->getObjectName() != "WIRE" && tempPtr->getLocked() == false) {
				static_cast<logicElementClass::LogicElement*>(tempPtr)->calculateOutput();
			}
			tempPtr = tempPtr->getNext();
		}
		elapsedTime= simulationClock.getElapsedTime();
	}
	setIsSimulating(false);
}



void Simulator::onWireDeleteHandleConnectedTo(objectclass::Object* eventObjPtr) {
	if (eventObjPtr->getObjectName() == "WIRE") {
		pinClass::Pin * pin1 = static_cast<wire::Wire*>(eventObjPtr)->getWirePinsPtrByIndex(0);
		pinClass::Pin* pin2 = static_cast<wire::Wire*>(eventObjPtr)->getWirePinsPtrByIndex(1);
		pin1->setConnectedToNullptr(pin2);
		pin2->setConnectedToNullptr(pin1);
		pin1->setWiresNullptr(eventObjPtr);
		pin2->setWiresNullptr(eventObjPtr);
	}
}

void Simulator::setIsSimulating(bool boolean) {
	isSimulating = boolean;
}