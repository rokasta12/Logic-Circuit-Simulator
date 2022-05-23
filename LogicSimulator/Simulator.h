#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Object.h"
#include "Pin.h"
#include "Wire.h"

namespace simulatorClass { 
	class Simulator {
		protected:
			sf::RenderWindow* window;
			objectclass::Object* headOfObjectList;
			bool isDrawingWire;
			bool isSimulating;
			sf::Clock simulationClock;
		public:
			Simulator(sf::RenderWindow *);
			void appendObjectList(objectclass::Object*);
			void deleteObjectFromObjectList(objectclass::Object*);

			objectclass::Object* getObjectPointerOfClicked(int,int);
			objectclass::Object* getObjectPointerOfSelected();

			void resetSelectedOfObjects();
			
			void createNewObject(std::string, float, float,bool isLocked=false);
			void createButtonToolBar();

			void traverseAndDrawAllObjects();
			sf::Vector2f getLockedObjectPositionByName(std::string);

			void createNewWire(float,float,pinClass::Pin *);

			objectclass::Object* getWireObjectPointer();


			bool getIsDrawingWire();
			void setIsDrawingWire(bool);

			//EVENT HANDLER,maus pin area icindeyse objenin pininin adresi dondur
			pinClass::Pin* getPinPointerOfObj(objectclass::Object*,float,float);
			pinClass::Pin* traverseListAndGetPinPointerOfObj(float, float);

			bool checkIfWireCanBeDrawn(pinClass::Pin*,wire::Wire*);
			void onWireDeleteHandleConnectedTo(objectclass::Object*);


			//simulation
			void startSimulation();
			void setIsSimulating(bool);
		
	};
}

