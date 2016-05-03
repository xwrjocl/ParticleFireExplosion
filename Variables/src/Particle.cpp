/*
 * Particle.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#include "Particle.h"
#include <cmath>
#include <stdlib.h>

namespace sdl_xwrjocl {

Particle::Particle():m_x(0),m_y(0) {

	m_direcction = ((2 * M_PI * rand())/RAND_MAX)-1;
	m_speed = (0.01 * rand())/RAND_MAX;

}

void Particle::updateParticle(){

	double xSpeed = m_speed * cos(m_direcction);
	double ySpeed = m_speed * sin(m_direcction);

	m_x += xSpeed;
	m_y += ySpeed;

}

} /* namespace sdl_xwrjocl */
