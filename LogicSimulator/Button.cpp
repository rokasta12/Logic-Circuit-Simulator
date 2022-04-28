#include "Button.h"
#include "Object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace objectclass;
using namespace buttonClass;

Button::Button(int textureSelectIndex, sf::RenderWindow*renderWindow){
	locked = true;
	state = false;
	selected = false;
	window = renderWindow;
	objectName = "BUTTON";
	next = NULL;
	buttonIndex = textureSelectIndex;
	cout << "button constr" << endl;
	string textureNames[] = { "START","STOP" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(textureSelectIndex);
}

void Button::drawObjectToWindow(){
	window->draw(sprite);
}