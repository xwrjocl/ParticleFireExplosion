#include <iostream>

#include <SDL.h>

#define SDL_MAIN_HANDLED
using namespace std;

int main(int argc, char* args[]) {

	const int SCREEN_HIGH = 800;
	const int SCREEN_WIDTH = 600;

	//Start SDL
	if (SDL_Init( SDL_INIT_EVERYTHING) < 0) {
		cout << "SLD_INIT failed" << endl;
		return 1;
	}
	cout << "SLD_INIT succeeded" << endl;

	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HIGH,
			SCREEN_WIDTH, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "ERROR creating windows: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_HIGH, SCREEN_WIDTH);

	if (renderer == NULL){
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		return 3;
	}

	if (texture == NULL){
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_HIGH * SCREEN_WIDTH];

	memset(buffer, 0xff00ffff, SCREEN_HIGH*SCREEN_WIDTH*sizeof(Uint32));

	for (int i=0; i< SCREEN_HIGH * SCREEN_WIDTH; i++){
		buffer[i]=0xff00ffff;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;

	SDL_Event event;

	while (!quit) {
		//Update particles
		//Draw particles
		//Check for messages/events

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}


	//Quit SDL
	delete []buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
