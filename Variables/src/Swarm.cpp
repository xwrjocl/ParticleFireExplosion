/*
 * Swarm.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#include "Swarm.h"

namespace sdl_xwrjocl {

Swarm::Swarm():lastime(0) {
	m_pParticle = new Particle[NPARTICLE];
}

const Particle * const Swarm::getParticle(){
	return m_pParticle;
}

void Swarm::updateSwarm (int slapset){

	int interval = slapset - lastime;

	for (int i=0; i<Swarm::NPARTICLE;i++){
		m_pParticle[i].updateParticle(interval);
	}

	lastime = slapset;

}

Swarm::~Swarm() {
	delete []m_pParticle;
}

} /* namespace sdl_xwrjocl */
