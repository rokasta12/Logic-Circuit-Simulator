#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace objectclass {

	class Object{
	protected:
	friend class Simulator;
		std::string objectName;
		Object* next;
		bool locked;
		bool state;
		bool selected;
		
		sf::Vector2f lockedObjectPosition;
		sf::RenderWindow* window;
		sf::Texture texture[2];
		sf::Sprite sprite;
		sf::Vertex selectedLineStrip[5];
	public:
			Object();
			void setTexture(std::string[],int);
			void setSpriteTexture(int textureIndex=0);
			void setNext(Object *);
			void setSelected(bool);
			void setLocked(bool);
			void setLockedObjectPosition();

			sf::Sprite getSprite();
			Object* getNext();
			bool getSelected();
			bool getLocked();
			std::string getObjectName();

			sf::FloatRect getGlobalBoundOfSprite();
			sf::Vector2f getLockedObjectPosition();

			void setSpritePosition(float,float);

			virtual void drawObjectToWindow();


			
<<<<<<< HEAD
			virtual void setLineVertice(float,float);
=======
			virtual void setLineVertice(float,float);//eventte static cast yapmamak icin, used for wires
>>>>>>> 8c70ed59b910d672f2fc80f95b22b8333fcf3402
			
	};

}
