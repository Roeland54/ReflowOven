#ifndef __COLOR_H__
#define __COLOR_H__

class Color
{
private:
	void update();
	
public:
	Color();
	Color(int r, int g, int b);
	int r;
	int g;
	int b;

	int rgb888;
	int rgb565;
};

#endif
