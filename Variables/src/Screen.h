/*
 * Screen.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace sdl_xwrjocl {

class Screen {

public:
	const static int SCREEN_HIGH = 600;
	const static int SCREEN_WIDTH = 800;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen() :m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL),m_buffer2(NULL) {};
	bool init();
	bool processEvent();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
	void update();
	void clean();
	void close();

};

} /* namespace sdl_xwrjocl */

#endif /* SCREEN_H_ */
