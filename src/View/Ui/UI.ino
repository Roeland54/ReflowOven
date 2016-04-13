#include <UTFT.h>
#include <UTouch.h>
#include "GUI.h"

UTFT tft(TFT01_24_16, 38, 39, 40, 41);
UTouch touch( 6, 5, 4, 3, 2);

GUI gui(&tft, &touch, &pressCallBack, &releaseCallBack);

char * onTxt = "ON";
char * offTxt = "OFF %4.2f";
char * toggleGrpTxt = "Toggle";
char * switchGrpTxt = "Switch";
char * toggleTxt = "TOG %u";
Button onBtn(new Point(10,15), new Size(125,92), onTxt);
Button offBtn(new Point(10,117), new Size(125,93), offTxt);
Button toggleBtn(new Point(10,15), new Size(125,195), toggleTxt);
GroupBox switchGrp(new Point(10,10), new Size(145,220), switchGrpTxt);
GroupBox toggleGrp(new Point(165,10), new Size(145,220), toggleGrpTxt);

int counter = 39;
float floatCounter = 3.141592656;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting up...");
  
  tft.InitLCD();
  tft.clrScr();
  tft.fillScr(VGA_WHITE);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  touch.InitTouch();
  touch.setPrecision(PREC_MEDIUM);

  Serial.println("Running");

  //fore, back, pressed, text
  onBtn.setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);
  offBtn.setColors(VGA_RED, VGA_RED, VGA_MAROON, VGA_WHITE);
  toggleBtn.setColors(VGA_BLUE, VGA_BLUE, VGA_NAVY, VGA_WHITE);

  //onBtn.addBinding((void*)&counter, INT);
  offBtn.addBinding((void*)&floatCounter, FLOAT);
  toggleBtn.addBinding((void*)&counter, INT);
  
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
  counter++;
  counter = counter>260?0:counter;
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

