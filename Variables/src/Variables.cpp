#include <iostream>

#include "Screen.h"

#define SDL_MAIN_HANDLED
using namespace std;
using namespace sdl_xwrjocl;

int main(int argc, char* args[]) {

	Screen screen;

	if (screen.init() == false){
		cout << "Error initializing the screen." << endl;
	}


	while (true) {
		//Update particles
		//Draw particles
		//Check for messages/events

		if (screen.processEvent() == true){
			break;
		}

		for (int y=0; y < screen.SCREEN_HIGH; y++){
			for (int x=0; x < screen.SCREEN_WIDTH; x++){
				screen.setPixel(y,x,128,0,255);
			}
		}

		// screen.setPixel(400,300,100,0,0);
		screen.update();

	}

	screen.close();


	return 0;
}
