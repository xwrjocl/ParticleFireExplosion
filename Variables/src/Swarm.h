/*
 * Swarm.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace sdl_xwrjocl {

class Swarm {
public:
	const static int NPARTICLE = 1000;
private:
	Particle * m_pParticle;

public:
	Swarm();
	const Particle * const getParticle();
	void updateSwarm ();
	virtual ~Swarm();
};

} /* namespace sdl_xwrjocl */

#endif /* SWARM_H_ */
