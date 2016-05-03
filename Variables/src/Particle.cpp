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

	m_xSpeed = 0.01*((2.0*rand())/RAND_MAX-1);
	m_ySpeed = 0.01*((2.0*rand())/RAND_MAX-1);
}

void Particle::updateParticle(){
	m_x += m_xSpeed;
	m_y += m_ySpeed;

	if (m_x <= -1.0 || m_x >=1.0){
		m_xSpeed = -m_xSpeed;
	}
	if (m_y <= -1.0 || m_y >=1.0){
		m_ySpeed = -m_ySpeed;
	}
}

} /* namespace sdl_xwrjocl */
