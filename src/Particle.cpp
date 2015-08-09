#include "Common.h"
#include "Particle.h"

float Particle::Hit(float ox, float oy, float *scale)
{
	float dx = x - ox;
	float dy = y - oy;
	float dz;

	if (dx*dx + dy*dy < radius*radius)
	{
		dz = sqrtf(radius*radius - dx*dx - dy*dy);
		*scale = dz / radius;
		return dz + z;
	}

	return -INF;
}

void Particle::Random()
{
	r = RND(1.0);
	g = RND(1.0);
	b = RND(1.0);
	x = RND(1000.0);
	y = RND(700.0);
	z = RND(1000.0);
	radius = RND(10) + 20;
}