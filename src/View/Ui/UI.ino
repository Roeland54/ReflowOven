#include <UTFT.h>
#include <UTouch.h>
#include "GUI.h"

UTFT tft(TFT01_24_16, 38, 39, 40, 41);
UTouch touch( 6, 5, 4, 3, 2);

GUI gui(&tft, &touch, &pressCallBack, &releaseCallBack);

char * onTxt = "ON";
char * offTxt = "OFF";
char * toggleGrpTxt = "Toggle";
char * switchGrpTxt = "Switch";
char * toggleTxt = "TOGGLE";
Button onBtn(new Point(10,15), new Size(125,92), onTxt);
Button offBtn(new Point(10,117), new Size(125,93), offTxt);
Button toggleBtn(new Point(10,15), new Size(125,195), toggleTxt);
GroupBox switchGrp(new Point(10,10), new Size(145,220), switchGrpTxt);
GroupBox toggleGrp(new Point(165,10), new Size(145,220), toggleGrpTxt);

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
  
  gui.addWidget(&switchGrp);
  switchGrp.addChild(&onBtn);
  switchGrp.addChild(&offBtn);
  gui.addWidget(&toggleGrp);
  toggleGrp.addChild(&toggleBtn);

  Serial.println("Widgets added");
  
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
  else if(_widget == &toggleBtn)
  {
    digitalWrite(13, !digitalRead(13));
  }
}

