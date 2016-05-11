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

Particle::Particle() :
		m_x(0), m_y(0) {

	init();
	m_speed *= m_speed;

}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direcction = ((2 * M_PI * rand()) / RAND_MAX) - 1;
	m_speed = (0.05 * rand()) / RAND_MAX;
}

void Particle::updateParticle(int interval) {

	m_direcction += interval * 0.0004;

	double xSpeed = m_speed * cos(m_direcction);
	double ySpeed = m_speed * sin(m_direcction);

	m_x += xSpeed * interval;
	m_y += ySpeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if (rand() < RAND_MAX/100){
		init();
	}

}

} /* namespace sdl_xwrjocl */
