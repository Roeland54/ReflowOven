#ifndef __UI_H__
#define __UI_H__

#include "Widget.h"
#include <UTFT.h>
#include <UTouch.h>
#include "Fonts.h"
#include "Button.h"
#include "Label.h"
#include "TextBox.h"
#include "CheckBox.h"
#include "ProgressBar.h"
#include "Panel.h"
#include "GroupBox.h"

typedef void (*Clicked)(Widget*);

class UI
{
public:
	UI(UTFT * _tft);
	UI(UTFT * _tft, UTouch * _touch);
	UI(UTFT * _tft, UTouch * _touch, Clicked _clickCallback);

	Widget * startWidget;
	UTFT * tft;
	UTouch * touch;

	Clicked clickCallback;

	void draw();
	void update();
	void addWidget(Widget * _widget);
};

#endif
