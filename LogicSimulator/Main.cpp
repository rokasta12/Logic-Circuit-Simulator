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

using namespace std;
using namespace objectclass;
using namespace andGateClass;
using namespace pinClass;
int main()
{
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 800.f));
    rectangle.setFillColor(sf::Color(61, 64, 61));
    sf::RectangleShape rectangle2(sf::Vector2f(800.f, 75.f));
    rectangle2.setFillColor(sf::Color(61, 64, 61));

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Logic Simulator");
    window.setFramerateLimit(60);

    simulatorClass::Simulator bum(&window);
  
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
                    eventObject=bum.getObjectPointerOfClicked(event.mouseButton.x, event.mouseButton.y);
                    if (eventObject) {                
                        if (eventObject->getLocked()) { //toolbar elementi ise
                            eventObject->setSelected(true);                       
                        }
                        else { //toolbar elementi degilse   
                            bum.resetSelectedOfObjects(); //butun selectlenmisleri sil bir

                            Pin* pinPtr = bum.getPinPointerOfObj(eventObject, event.mouseButton.x, event.mouseButton.y);
                            if (pinPtr) {//wire cizmeyi dene
                                bum.createNewWire(event.mouseButton.x, event.mouseButton.y, pinPtr);
                                bum.setIsDrawingWire(true);
                            }
                            else {//wire cizme olayi degilse selectle
                                cout << "selected" << endl;
                                eventObject->setSelected(true);
                            }
                        }
                    }
                    else {
                        bum.resetSelectedOfObjects();
                    }
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (bum.getIsDrawingWire()) {//move drawing wire
                        Object* wireObjectPointer = bum.getWireObjectPointer();
                        if (wireObjectPointer) {
                            wireObjectPointer->setLineVertice(event.mouseMove.x, event.mouseMove.y);
                        }
                    }
                    else { //move locked sprite
                        Object* eventObject = bum.getObjectPointerOfSelected();
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
                    if (bum.getIsDrawingWire()) { //wire yerlestirebiliyor mu kontrol et, yerlestiremezse sil
                        Pin* pinPtrOfObj = bum.traverseListAndGetPinPointerOfObj(event.mouseButton.x, event.mouseButton.y);
                        Object* wireObjectPointer = bum.getWireObjectPointer();
                        wire::Wire* wirePtr = static_cast<wire::Wire*>(wireObjectPointer);
                        if (bum.checkIfWireCanBeDrawn(pinPtrOfObj,wirePtr)) {                       
                            wirePtr->setPointerOfSecondPin(pinPtrOfObj);
                           
                            //connectedTo setleme mekaný
                            Pin* basePinPtr = wirePtr->getWirePinsPtrByIndex(0);//wire'ýn ilk ucundaki pini aldým
                            int basePinNumOfConnections=basePinPtr->getNumOfConnections();
                            int targetPinNumOfConnections = pinPtrOfObj->getNumOfConnections();
                            basePinPtr->setConnectedToByIndex(pinPtrOfObj, basePinNumOfConnections);
                            pinPtrOfObj->setConnectedToByIndex(basePinPtr, targetPinNumOfConnections);
                            basePinPtr->setNumOfConnections(true);
                            pinPtrOfObj->setNumOfConnections(true);
                        }
                        else {
                            bum.deleteObjectFromObjectList(wireObjectPointer);
                        }                       
                        bum.setIsDrawingWire(false);                        
                    }
                    else{ //yeni lojik element yaratma
                        Object* eventObject = bum.getObjectPointerOfSelected();
                        if(eventObject){
                            if (eventObject->getLocked()) {  //locked object position reset, create new object           
                                string eventObjName = eventObject->getObjectName();      
                                sf::Vector2f lockedEventObjectPosition = eventObject->getLockedObjectPosition();                   
                                eventObject->setSpritePosition(lockedEventObjectPosition.x, lockedEventObjectPosition.y);
                                eventObject->setSelected(false);
                                float mousePosX = event.mouseButton.x;
                                float mousePosY = event.mouseButton.y;
                                bum.createNewObject(eventObjName, mousePosX, mousePosY);
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
                    eventObject = bum.getObjectPointerOfSelected();
                    if (eventObject) {
                        if (!(eventObject->getLocked())) { //check if toolbar element or not
                            if (eventObject->getObjectName() == "WIRE") {
                               Pin* pin1= static_cast<wire::Wire*>(eventObject)->getWirePinsPtrByIndex(0);
                               Pin* pin2 = static_cast<wire::Wire*>(eventObject)->getWirePinsPtrByIndex(1);
                               pin1->setConnectedToNullptr(pin2);
                               pin2->setConnectedToNullptr(pin1);
                            }
                            bum.deleteObjectFromObjectList(eventObject);
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Numpad5)
                {
                    bum.startSimulation();
                }
            }







        }

        window.clear(sf::Color::Black);

        window.draw(rectangle);
        window.draw(rectangle2);
        bum.traverseAndDrawAllObjects();
   
        window.display();
    }
    return 0;
}