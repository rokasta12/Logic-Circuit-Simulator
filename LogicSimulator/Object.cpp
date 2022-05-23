#include "Object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace objectclass;

Object::Object() {
	locked = false;
	state = false;
	selected = false;
	next = NULL;
	selectedLineStrip[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255));
	selectedLineStrip[1] = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255));
	selectedLineStrip[2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255));
	selectedLineStrip[3] = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255));
	selectedLineStrip[4] = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255));
}

void Object::setTexture(std::string textureArr[],int textureNamesLength) {
	for (int i = 0; i < textureNamesLength; i++) {
		string assetURL = "../assets/" + *(textureArr + i) + ".png";
		if (!texture[i].loadFromFile(assetURL))
		{
			cout << "Failed to load texture!" << endl;
		}
	}
}

void Object::setSpriteTexture(int textureIndex) {
	sprite.setTexture(texture[textureIndex]);
}

sf::Sprite Object::getSprite() {
	return sprite;
}

void Object::drawObjectToWindow() {
		if (selected) {
			window->draw(selectedLineStrip,5,sf::LineStrip);
		}
		window->draw(sprite);
}



Object * Object::getNext() {
	if (this) {
		return next;
	}
	else {
		return 0;
	}
}

void Object::setNext(Object *ptr) {
	next = ptr;
}

sf::FloatRect Object::getGlobalBoundOfSprite() {
	return this->getSprite().getGlobalBounds();
}

void Object::setSelected(bool boolean) {
	if (boolean) {
		if (!locked) {
			sf::FloatRect rect = getGlobalBoundOfSprite();
			selectedLineStrip[0] = sf::Vertex(sf::Vector2f(rect.left, rect.top), sf::Color(255, 0, 0, 255));
			selectedLineStrip[1] = sf::Vertex(sf::Vector2f(rect.left+rect.width, rect.top), sf::Color(255, 0, 0, 255));
			selectedLineStrip[2] = sf::Vertex(sf::Vector2f(rect.left+rect.width, rect.top+rect.height), sf::Color(255, 0, 0, 255));
			selectedLineStrip[3] = sf::Vertex(sf::Vector2f(rect.left, rect.top+rect.height), sf::Color(255, 0, 0, 255));
			selectedLineStrip[4] = sf::Vertex(sf::Vector2f(rect.left , rect.top), sf::Color(255, 0, 0, 255));
		}
	}
	else {
		//selectedLineStrip->color = sf::Color(255, 0, 0, 255);
	}
	selected = boolean;
}

bool Object::getSelected() {
	return selected;
}

void Object::setSpritePosition(float x,float y) {
	sprite.setPosition(x, y);
}

void Object::setLocked(bool boolean){
	locked = boolean;
}
bool Object::getLocked() {
	return locked;
}

string Object::getObjectName() {
	if (this) {
	 return objectName;
	}
	else {
		return 0;
	}

}

void Object::setLockedObjectPosition() {
	lockedObjectPosition = sprite.getPosition();
}

sf::Vector2f Object::getLockedObjectPosition() {
	return lockedObjectPosition;
}



void Object::setLineVertice(float x,float y) {

}
