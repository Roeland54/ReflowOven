#include "UI.h"

UI::UI(UTFT * _tft)
{
	tft = _tft;
}

UI::UI(UTFT * _tft, UTouch * _touch) : UI(_tft)
{
	touch = _touch;
}

UI::UI(UTFT * _tft, UTouch * _touch, Clicked _clickCallback) : UI(_tft, _touch)
{
	clickCallback = _clickCallback;
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

void UI::update()
{
	Widget * last;

	if(touch->dataAvailable())
	{
		if(startWidget)
		{
			touch->read();
			int x = touch->getX();
			int y = touch->getY();
			if ((x!=-1) and (y!=-1))
			{
				startWidget->checkHit(x, y, &last);
			}

			if(last)
				clickCallback(last);

		}
	}
}
