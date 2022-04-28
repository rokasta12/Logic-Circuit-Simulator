#include "Dff.h"
#include <iostream>
#include <string>

using namespace std;
using namespace dff;

Dff::Dff(sf::RenderWindow* renderWindow) {
	cout << "DFF constructor" << endl;
	objectName = "DFF";
	window = renderWindow;
	numPins = 4;
	string textureNames[] = { "DFF" };
	int textureNamesLength = sizeof(textureNames) / sizeof(textureNames[0]);
	setTexture(textureNames, textureNamesLength);
	setSpriteTexture(0);
	
}
