#include <iostream>
#include <SFML/Graphics.hpp>
#include "Simulator.h"
#include <string>

#include "AndGate.h"
#include "ORGate.h"
#include "NotGate.h"
#include "Gnd.h"
#include "Dff.h"
#include "Vdd.h"
#include "XorGate.h"
#include "Led.h"
#include "Wire.h"
#include "Button.h"

using namespace std;
using namespace objectclass;
using namespace andGateClass;
using namespace pinClass;
int main()
{
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 900.f));
    rectangle.setFillColor(sf::Color(61, 64, 61));
    sf::RectangleShape rectangle2(sf::Vector2f(900.f, 75.f));
    rectangle2.setFillColor(sf::Color(61, 64, 61));

    // create the window
    sf::RenderWindow window(sf::VideoMode(900,900), "Logic Simulator");
    window.setFramerateLimit(60);

    simulatorClass::Simulator simulator(&window);
  
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){ //select an object or deselect all
                                              
                    Object* eventObject = NULL;
                    eventObject=simulator.getObjectPointerOfClicked(event.mouseButton.x, event.mouseButton.y);
                    if (eventObject) {                
                        if (eventObject->getLocked()) { //toolbar elementi ise
                            if (eventObject->getObjectName() == "BUTTON") {
                                buttonClass::Button* buttonPtr = static_cast<buttonClass::Button*>(eventObject);
                                if (buttonPtr->getButtonIndex()) { //start simulation if 0
<<<<<<< HEAD
                                    simulator.setIsSimulating(false);
                                }
                                else {
                                    simulator.setIsSimulating(true);
                                    simulator.startSimulation();
=======
                                    bum.setIsSimulating(false);
                                }
                                else {
                                    bum.setIsSimulating(true);
                                    bum.startSimulation();
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
                                }
                            }
                            else { //lojik kapilarý suruklemek icin selectle
                            eventObject->setSelected(true);                       
                            }
                        }
                        else { //toolbar elementi degilse   
                            simulator.resetSelectedOfObjects(); //butun selectlenmisleri sil bir

                            Pin* pinPtr = simulator.getPinPointerOfObj(eventObject, event.mouseButton.x, event.mouseButton.y);
                            if (pinPtr) {//wire cizmeyi dene
                                simulator.createNewWire(event.mouseButton.x, event.mouseButton.y, pinPtr);
                                simulator.setIsDrawingWire(true);
                            }
                            else {//wire cizme olayi degilse selectle
                                eventObject->setSelected(true);
                            }
                        }
                    }
                    else {
                        simulator.resetSelectedOfObjects();
                    }
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (simulator.getIsDrawingWire()) {//move drawing wire
                        Object* wireObjectPointer = simulator.getWireObjectPointer();
                        if (wireObjectPointer) {
                            wireObjectPointer->setLineVertice(event.mouseMove.x, event.mouseMove.y);
                        }
                    }
                    else { //move locked sprite
                        Object* eventObject = simulator.getObjectPointerOfSelected();
                        if (eventObject) {  
                            if (eventObject->getLocked()) {
                                float mouseX = event.mouseMove.x;
                                float mouseY = event.mouseMove.y;
                                eventObject->setSpritePosition(mouseX, mouseY);
                            }
                        }
                    }
                   
                }
              

            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (simulator.getIsDrawingWire()) { //wire yerlestirebiliyor mu kontrol et, yerlestiremezse sil
                        Pin* pinPtrOfObj = simulator.traverseListAndGetPinPointerOfObj(event.mouseButton.x, event.mouseButton.y);
                        Object* wireObjectPointer = simulator.getWireObjectPointer();
                        wire::Wire* wirePtr = static_cast<wire::Wire*>(wireObjectPointer);
                        if (simulator.checkIfWireCanBeDrawn(pinPtrOfObj,wirePtr)) {                       
                            wirePtr->setPointerOfSecondPin(pinPtrOfObj);
                           
                            //connectedTo setleme mekaný
                            Pin* basePinPtr = wirePtr->getWirePinsPtrByIndex(0);//wire'ýn ilk ucundaki pini aldým
                            int basePinNumOfConnections=basePinPtr->getNumOfConnections();
                            int targetPinNumOfConnections = pinPtrOfObj->getNumOfConnections();
                            basePinPtr->setConnectedToByIndex(pinPtrOfObj, basePinNumOfConnections);
                            pinPtrOfObj->setConnectedToByIndex(basePinPtr, targetPinNumOfConnections);
                            basePinPtr->setWiresByIndex(wireObjectPointer, basePinNumOfConnections);
                            pinPtrOfObj->setWiresByIndex(wireObjectPointer, targetPinNumOfConnections);
                            basePinPtr->setNumOfConnections(true);
                            pinPtrOfObj->setNumOfConnections(true);
                        }
                        else {
                            simulator.deleteObjectFromObjectList(wireObjectPointer);
                        }                       
                        simulator.setIsDrawingWire(false);                        
                    }
                    else{ //yeni lojik element yaratma
                        Object* eventObject = simulator.getObjectPointerOfSelected();
                        if(eventObject){
                            if (eventObject->getLocked()) {  //locked object position reset, create new object           
                                string eventObjName = eventObject->getObjectName();      
                                sf::Vector2f lockedEventObjectPosition = eventObject->getLockedObjectPosition();                   
                                eventObject->setSpritePosition(lockedEventObjectPosition.x, lockedEventObjectPosition.y);
                                eventObject->setSelected(false);
                                float mousePosX = event.mouseButton.x;
                                float mousePosY = event.mouseButton.y;
                                simulator.createNewObject(eventObjName, mousePosX, mousePosY);
                            }
                        }
                    }
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Delete)
                {
                    Object* eventObject = NULL;
                    eventObject = simulator.getObjectPointerOfSelected();
                    if (eventObject) {
                        if (!(eventObject->getLocked())) { //check if toolbar element or not
<<<<<<< HEAD
                            simulator.onWireDeleteHandleConnectedTo(eventObject);
=======
                            bum.onWireDeleteHandleConnectedTo(eventObject);
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
                            //sprite silerken bagli wire'larida silme kýsmý
                            if (eventObject->getObjectName() != "WIRE") {
                                logicElementClass::LogicElement* logicElePtr = static_cast<logicElementClass::LogicElement*>(eventObject);
                                int numPins=logicElePtr->getNumPins();
                                for (int i = 0; i < numPins; i++) {
                                    pinClass::Pin* pinPtr = logicElePtr->getPinsByIndex(i);
                                    int numOfConnectionsOfPin = pinPtr->getNumOfConnections();
                                    for (int j = 0; j < numOfConnectionsOfPin; j++) {
                                        Object* wireObjPtr=pinPtr->getWiresByIndex(j);
                                        if (wireObjPtr) {
<<<<<<< HEAD
                                            simulator.onWireDeleteHandleConnectedTo(wireObjPtr);
                                            simulator.deleteObjectFromObjectList(wireObjPtr);
=======
                                            bum.onWireDeleteHandleConnectedTo(wireObjPtr);
                                            bum.deleteObjectFromObjectList(wireObjPtr);
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
                                        }
                                    }
                                }
                            }
                            //sprite silerken bagli wire'larida silme kýsmý son
<<<<<<< HEAD
                            simulator.deleteObjectFromObjectList(eventObject);
=======
                            bum.deleteObjectFromObjectList(eventObject);
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Numpad5)
                {
                    simulator.startSimulation();
                }
            }







        }

        window.clear(sf::Color::Black);

        window.draw(rectangle);
        window.draw(rectangle2);
        simulator.traverseAndDrawAllObjects();
   
        window.display();
    }
    return 0;
}