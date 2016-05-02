/*
 * Particle.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#include "Particle.h"
#include <stdlib.h>

namespace sdl_xwrjocl {

Particle::Particle() {
	m_x = (2.0 * rand() / RAND_MAX) - 1;
	m_y = (2.0 * rand() / RAND_MAX) - 1;
}

} /* namespace sdl_xwrjocl */
