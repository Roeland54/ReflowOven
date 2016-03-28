#include <UTFT.h>
#include <UTouch.h>
#include "UI.h"

UTFT tft(TFT01_24_16, 38, 39, 40, 41);
UTouch touch( 6, 5, 4, 3, 2);

UI ui(&tft, &touch, &callBack);

char * txt = "Button";
Button btn(new Point(10,10), new Size(100,50), txt);

void setup()
{
  tft.InitLCD();
  tft.clrScr();
  tft.setColor(VGA_RED);
  tft.setBackColor(VGA_AQUA);
  tft.fillScr(VGA_YELLOW);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  touch.InitTouch();
  touch.setPrecision(PREC_MEDIUM);

  Serial.begin(9600);

  Serial.println("Running");
  
  ui.addWidget(&btn);

  Serial.println("Button added");
  
  ui.draw();

  Serial.println("UI drawn");
}

void loop()
{
  ui.update();
  delay(100);
}

void callBack(Widget * _widget)
{
  digitalWrite(13, !digitalRead(13));
  Serial.println("Click!");
}

