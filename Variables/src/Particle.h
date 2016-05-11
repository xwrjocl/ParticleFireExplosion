/*
 * Particle.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: qclajos
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace sdl_xwrjocl {

struct Particle {

	double m_x;
	double m_y;

	double m_direcction;
	double m_speed;

private:
	void init();

public:
	Particle();
	void updateParticle(int interval);
};

} /* namespace sdl_xwrjocl */

#endif /* PARTICLE_H_ */
