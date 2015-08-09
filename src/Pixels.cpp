#include <list>

#include "Common.h"
#include "Particle.h"
#include "Pixels.h"

Pixels::Pixels(unsigned int w, unsigned int h)
{
	m_w = w;
	m_h = h;
	m_pixels = new unsigned char[w*h * 4];
}

Pixels::~Pixels()
{
	if (m_pixels)
	{
		delete[] m_pixels;
		m_pixels = nullptr;
	}
}

void Pixels::Random()
{
	for (int i = 0; i < m_w * m_h * 4; i += 4)
	{
		m_pixels[i] = (255)*rand() / RAND_MAX;
		m_pixels[i + 1] = (255)*rand() / RAND_MAX;
		m_pixels[i + 2] = (255)*rand() / RAND_MAX;
		m_pixels[i + 3] = 255;
	}
}

void Pixels::Render()
{
	std::list<Particle> particles;
	for (int i = 0; i < PARTICLES; i++)
	{
		Particle part;
		part.Random();
		particles.push_back(part);
	}

	// ray tracing
	unsigned int index;
	unsigned int count_x;
	unsigned int count_y;
	float temp_r;
	float temp_g;
	float temp_b;
	float maxz;

	time_t start = GetMicrosecondeNow();

	printf("Render begin >>>\n");
	for (count_x = 0; count_x < ((unsigned int)m_w); count_x++)
	{
		for (count_y = 0; count_y < ((unsigned int)m_h); count_y++)
		{
			index = count_y * ((unsigned int)m_w) + count_x;
			temp_r = 0;
			temp_g = 0;
			temp_b = 0;
			maxz = -INF;

			for (auto iter = particles.begin(); iter != particles.end(); iter++)
			{
				float fscale = 1;
				float distance = iter->Hit(count_x, count_y, &fscale);
				if (distance > maxz)
				{
					temp_r = iter->r * fscale;
					temp_g = iter->g * fscale;
					temp_b = iter->b * fscale;
					maxz = distance;
				}
			}
			m_pixels[index * 4 + 0] = (int)(temp_r * 255);
			m_pixels[index * 4 + 1] = (int)(temp_g * 255);
			m_pixels[index * 4 + 2] = (int)(temp_b * 255);
			m_pixels[index * 4 + 3] = (int)(125);

			//printf("the RGBA: %d, %d, %d, %d.\n", (int)(temp_r * 255), (int)(temp_g * 255), (int)(temp_b * 255));
		}
	}

	time_t end = GetMicrosecondeNow();
	time_t diff = end - start;

	printf("start:%lld\nend:%lld\ntotal use: %lld\n", start, end, diff);
}