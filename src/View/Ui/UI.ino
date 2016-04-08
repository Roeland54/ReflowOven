#include <UTFT.h>
#include <UTouch.h>
#include "UI.h"

UTFT tft(TFT01_24_16, 38, 39, 40, 41);
UTouch touch( 6, 5, 4, 3, 2);

UI gui(&tft, &touch, &pressCallBack, &releaseCallBack);

char * onTxt = "ON";
char * offTxt = "OFF";
Button onBtn(new Point(10,10), new Size(300,105), onTxt);
Button offBtn(new Point(10,125), new Size(300,105), offTxt);

void setup()
{
  
  Serial.begin(9600);
  Serial.println("Starting up...");
  
  tft.InitLCD();
  tft.clrScr();
  tft.setColor(VGA_RED);
  tft.setBackColor(VGA_AQUA);
  tft.fillScr(VGA_YELLOW);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  touch.InitTouch();
  touch.setPrecision(PREC_MEDIUM);

  Serial.println("Running");
  
  gui.addWidget(&onBtn);
  gui.addWidget(&offBtn);

  Serial.println("Button added");
  
  gui.draw();

  Serial.println("UI drawn");
}

void loop()
{
  gui.update();
  delay(100);
}

void pressCallBack(Widget * _widget)
{
  if(_widget == &onBtn)
  {
    digitalWrite(13, HIGH);
    //Serial.println("Press");
  }
}

void releaseCallBack(Widget * _widget)
{
  if(_widget == &offBtn)
  {
    digitalWrite(13, LOW);
    //Serial.println("Press");
  }
}

