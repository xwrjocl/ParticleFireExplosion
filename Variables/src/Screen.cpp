/*
 * Screen.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#include "Screen.h"

namespace sdl_xwrjocl {

bool Screen::init(){


	//Start SDL
	if (SDL_Init( SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HIGH,
			SCREEN_WIDTH, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_HIGH, SCREEN_WIDTH);

	if (m_renderer == NULL){
		SDL_DestroyWindow(m_window);
		return false;
	}

	if (m_texture == NULL){
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[SCREEN_HIGH * SCREEN_WIDTH];

	memset(m_buffer, 0xff00ffff, SCREEN_HIGH*SCREEN_WIDTH*sizeof(Uint32));

/*	for (int i=0; i< SCREEN_HIGH * SCREEN_WIDTH; i++){
		m_buffer[i]=0xff00ffff;
	}*/

	return true;
}

bool Screen::processEvent(){

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return true;
		}
	}

	return false;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

	Uint32 color = 0;

	color += red;
	color <<=8;
	color += green;
	color <<=8;
	color += blue;
	color <<=8;
	color += 0xFF;

	m_buffer [(y*SCREEN_WIDTH) + x] = color;

}

void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::close(){
	//Quit SDL
	delete []m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace sdl_xwrjocl */
