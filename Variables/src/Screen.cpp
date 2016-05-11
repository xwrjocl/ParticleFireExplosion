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
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
			SCREEN_HIGH, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HIGH);

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

	m_buffer1 = new Uint32[SCREEN_HIGH * SCREEN_WIDTH];
	m_buffer2 = new Uint32[SCREEN_HIGH * SCREEN_WIDTH];

	memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HIGH*sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HIGH*sizeof(Uint32));

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

	if (x<0||x>=SCREEN_WIDTH || y<0 || y>= SCREEN_HIGH){
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<=8;
	color += green;
	color <<=8;
	color += blue;
	color <<=8;
	color += 0xFF;

	m_buffer1 [(y*SCREEN_WIDTH) + x] = color;

}

void Screen::boxBlur(){

	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y=0; y<SCREEN_HIGH; y++){
		for (int x=0; x<SCREEN_WIDTH;x++){
			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */
			int redTotal=0;
			int greenTotal=0;
			int blueTotal=0;

			for (int row =-1; row <=1; row++){
				for (int col =-1;col<=1;col++){
					int currentX = x + col;
					int currentY = y + row;

					if (currentX>=0 && currentX< SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HIGH){
						Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}

				}
			}

			Uint8 red = redTotal/9;
			Uint8  green = greenTotal/9;
			Uint8  blue = blueTotal/9;

			setPixel (x,y,red,green,blue);

		}
	}

}

void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::clean(){
	memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HIGH*sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HIGH*sizeof(Uint32));
}

void Screen::close(){
	//Quit SDL
	delete []m_buffer1;
	delete []m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace sdl_xwrjocl */
