#pragma once
#include "Object.h"
#include "Pin.h"

namespace logicElementClass {

	class LogicElement :public objectclass::Object{

	protected:
		enum pinPos {notI1x=0,notI1y=25,notO1x=88,notO1y=25,
					threePinI1x=0,threePinI1y=10,threePinI2x=0,threePinI2y=40,threePinO1x=88,threePinO1y=25,
					dffI1x=0,dffI1y=15,dffI2x=0,dffI2y=35,dffO1x=88,dffO1y=15,dffO2x=88,dffO2y=55,
					gndI1x=17,gndI1y=0,vddI1x=25,vddI1y=49,clockI1x=69,clockI1y=25,
					ledI1x=9,ledI1y=67
		};

		pinClass::Pin pins[4];
		int numPins;
	public:
			LogicElement();

			void setPins();// pins are set in simulator.cpp -> createNewObject

			pinClass::Pin *getPinsByIndex(int);
			int getNumPins();

			virtual void calculateOutput();
<<<<<<< HEAD
=======

			// arguman index, output pins[]'de hangi index'deyse onu ver
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
			void directOutputPinResultToConnectedPins(int);
		
	};
}

