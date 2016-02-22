#ifndef __PROGRESSBAR_H__
#define __PROGRESSBAR_H__

#include "Widget.h"

class ProgressBar : public Widget
{
public:
	ProgressBar(Point * _point, Size * _size);
	void draw();
	void draw(int _x, int _y, bool useLoc);
	
	int percentage;
	void setPercentage(int _percentage);
};

#endif
