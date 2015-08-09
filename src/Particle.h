#ifndef _PARTICLE_H
#define _PARTICLE_H

class Particle 
{
public:
	Particle() {}
	~Particle() {}

public:
	float Hit(float ox, float oy, float *scale);

	void Random();

public:
	float x, y, z;
	float radius;
	float r, b, g;
};

#endif