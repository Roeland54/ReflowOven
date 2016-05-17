#include "ReflowView.h"

typedef void (ReflowView::*TouchCallbackPointer)(Widget*);

ReflowView::ReflowView()
{

}

ReflowView::ReflowView(ClickedCallbackPointer press, ClickedCallbackPointer release)
{
  tft = new UTFT(MODEL, RS, WR, CSS, RST);
  Serial.println("Starting up...");

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.println("Running");
  touch = new UTouch(A, B, C, D, E);

  gui = new GUI(tft, touch, press, release);

  tft->InitLCD();
  tft->clrScr();
  tft->fillScr(VGA_RED);

  touch->InitTouch();
  touch->setPrecision(PREC_MEDIUM);

  DrawStartupPage();
}


void ReflowView::pressCallBack(Widget * _widget)
{
  //Serial.println("press");
}

void ReflowView::releaseCallBack(Widget * _widget)
{

}

void ReflowView::DrawStartupPage()
{
  char * onTxt = "ON";
  onBtn = new Button(new Point(10,15), new Size(125,92), onTxt);

  Serial.println("Button created");
  delay(50);
  //fore, back, pressed, text
  onBtn->setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);

  Serial.println("colors set");
  delay(50);

  gui->addWidget(onBtn);
  Serial.println("Widget added");
  delay(50);

  gui->draw();

}

void ReflowView::Update()
{
  //Serial.println("Update ui in reflowview");
  //delay(10);
  gui->update();
}
