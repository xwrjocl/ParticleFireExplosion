#include <iostream>
#include "Screen.h"
#include <time.h>
#include "Swarm.h"

#define SDL_MAIN_HANDLED
using namespace std;
using namespace sdl_xwrjocl;

int main(int argc, char* args[]) {

	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing the screen." << endl;
	}

	Swarm swarm;
	int slapset = 0;
	while (true) {
		//Update particles
		//Draw particles
		//Check for messages/events

		if (screen.processEvent() == true) {
			break;
		}
		screen.clean();
		slapset = SDL_GetTicks();
		unsigned int red = (1 + sin(slapset * 0.0001)) * 128;
		unsigned int green = (1 + sin(slapset * 0.0002)) * 128;
		unsigned int blue = (1 + sin(slapset * 0.0003)) * 128;

		const Particle * const pParticles = swarm.getParticle();
		for (int i = 0; i < Swarm::NPARTICLE; i++) {
			Particle particle = pParticles[i];
			int x = ((particle.m_x + 1) * Screen::SCREEN_WIDTH / 2);
			int y = (particle.m_y * Screen::SCREEN_WIDTH / 2)
					+ Screen::SCREEN_HIGH / 2;
			screen.setPixel(x, y, red, green, blue);
		}

		swarm.updateSwarm(slapset);

		screen.update();

	}

	screen.close();

	return 0;
}
