#include "ReflowView.h"

ReflowView::ReflowView()
{
  tft = new UTFT(MODEL, RS, WR, CSS, RST);
  Serial.println("Starting up...");
  tft->InitLCD();
  tft->clrScr();
  tft->fillScr(VGA_RED);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.println("Running");
  touch = new UTouch(A, B, C, D, E);

  touch->InitTouch();
  touch->setPrecision(PREC_MEDIUM);

  gui = new GUI(tft);
  DrawStartupPage();
}


void ReflowView::pressCallBack(Widget * _widget)
{

}

void ReflowView::releaseCallBack(Widget * _widget)
{

}

void ReflowView::DrawStartupPage()
{
  char * onTxt = "ON";

  onBtn = new Button(new Point(10,15), new Size(125,92), onTxt);


  //fore, back, pressed, text
  onBtn->setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);


  //gui->addWidget(onBtn);


  //gui->draw();
  Serial.println("UI drawn");

}

void ReflowView::Update()
{
  gui->update();
}
