#ifndef _PIXELS_H
#define _PIXELS_H

class Pixels
{
public:
	Pixels(unsigned int w, unsigned int h);
	~Pixels();

	void Random();
	unsigned char* GetPixels() { return m_pixels; }

	void Render();
private:
	unsigned int m_w;
	unsigned int m_h;
	unsigned char* m_pixels;
};
#endif