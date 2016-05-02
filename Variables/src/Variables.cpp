#include <iostream>
#include <cmath>
#include "Screen.h"

#define SDL_MAIN_HANDLED
using namespace std;
using namespace sdl_xwrjocl;

int main(int argc, char* args[]) {

	Screen screen;

	if (screen.init() == false){
		cout << "Error initializing the screen." << endl;
	}


	int slapset=0;
	while (true) {
		//Update particles
		//Draw particles
		//Check for messages/events

		if (screen.processEvent() == true){
			break;
		}

		slapset = SDL_GetTicks();
		unsigned int red = (1+sin(slapset * 0.0001))*128;
		unsigned int green = (1+sin(slapset * 0.0002))*128;
		unsigned int blue = (1+sin(slapset * 0.0003))*128;


		// screen.setPixel(400,300,100,0,0);
		for (int y=0; y < screen.SCREEN_HIGH; y++){
			for (int x=0; x < screen.SCREEN_WIDTH; x++){
				screen.setPixel(y,x,red,green,blue);
			}
		}

		screen.update();

	}

	screen.close();


	return 0;
}
