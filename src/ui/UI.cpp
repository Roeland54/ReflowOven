#include "UI.h"

UI::UI(UTFT * _tft)
{
	tft = _tft;
}

void UI::addWidget(Widget * _widget)
{
	_widget->tft = tft;

	if(startWidget)
		startWidget->setNext(_widget);
	else
		startWidget = _widget;
}

void UI::draw()
{
	if(startWidget)
		startWidget->draw();
}