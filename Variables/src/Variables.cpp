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
	}

	screen.close();


	return 0;
}
