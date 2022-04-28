#pragma once
#include "Object.h"

namespace buttonClass {

	class Button:public objectclass::Object{
	protected:
		int buttonIndex; //0 for START, 1 for STOP
	public:
		Button(int, sf::RenderWindow*);
		void drawObjectToWindow();
		
	};
}

