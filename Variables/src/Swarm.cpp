/*
 * Swarm.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#include "Swarm.h"

namespace sdl_xwrjocl {

Swarm::Swarm() {
	m_pParticle = new Particle[NPARTICLE];
}

const Particle * const Swarm::getParticle(){
	return m_pParticle;
}

Swarm::~Swarm() {
	delete []m_pParticle;
}

} /* namespace sdl_xwrjocl */
