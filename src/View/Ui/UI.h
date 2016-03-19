#ifndef __UI_H__
#define __UI_H__

#include "Widget.h"
#include <UTFT.h>
#include "Fonts.h"

#include "Button.h"
#include "Label.h"
#include "TextBox.h"
#include "CheckBox.h"
#include "ProgressBar.h"
#include "Panel.h"
#include "GroupBox.h"

class UI
{
public:
	UI(UTFT * _tft);

	Widget * startWidget;
	UTFT * tft;

	void draw();
	void addWidget(Widget * _widget);
};

#endif