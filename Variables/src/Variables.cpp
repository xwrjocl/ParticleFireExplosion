#include <iostream>

#include <SDL.h>

#define SDL_MAIN_HANDLED
using namespace std;


int main( int argc, char* args[] )
{

	const int SCREEN_HIGH = 800;
	const int SCREEN_WIDTH = 600;

    //Start SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0){
    	cout << "SLD_INIT failed" << endl;
    	return 1;
    }
    cout << "SLD_INIT succeeded" << endl;

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_HIGH,SCREEN_WIDTH,SDL_WINDOW_SHOWN );

    if(window == NULL){
    	cout << "ERROR creating windows: " << SDL_GetError() << endl;;
    	SDL_Quit();
    	return 2;
    }

    bool quit = false;

    SDL_Event event;

    while(!quit){
    	//Update particles
    	//Draw particles
    	//Check for messages/events

    	while(SDL_PollEvent(&event)){
    		if(event.type == SDL_QUIT){
    			quit = true;
    		}
    	}
    }


    SDL_DestroyWindow(window);
    //Quit SDL
    SDL_Quit();

    return 0;
}
