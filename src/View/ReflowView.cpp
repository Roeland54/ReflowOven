#include "ReflowView.h"

typedef void (ReflowView::*TouchCallbackPointer)(Widget*);
char * wantedLblTxt = "Wanted :";
char * realLblTxt = "Actual :";


ReflowView::ReflowView()
{

}

ReflowView::ReflowView(
    ClickedCallbackPointer press,
   ClickedCallbackPointer release,
   float *wantedTemp,
   float *realTemp)
{
  tft = new UTFT(MODEL, RS, WR, CSS, RST);
  Serial.println("Starting up...");

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.println("Running");
  touch = new UTouch(A, B, C, D, E);

  gui = new GUI(tft, touch, press, release);
  this->wantedTemp = wantedTemp;
  this->realTemp = realTemp;

  tft->InitLCD();
  tft->clrScr();
  tft->fillScr(VGA_WHITE);

  touch->InitTouch();
  touch->setPrecision(PREC_MEDIUM);

  DrawStartupPage();
}


void ReflowView::pressCallBack(Widget * _widget)
{
  Serial.println("press");
  //delay(50);
  if (_widget == onBtn)
  {
    DrawFlowPage();
  }
  else if (_widget == offBtn)
  {
    DrawStartupPage();
  }
  else if (_widget == setBtn)
  {

  }

}

void ReflowView::releaseCallBack(Widget * _widget)
{

}

void ReflowView::DrawStartupPage()
{
  gui->clear();

  char * onTxt = "START";
  char * offTxt = "STOP";
  char * setTxt = "SETTINGS";
  onBtn = new Button(new Point(17,18), new Size(135,92), onTxt);
  offBtn = new Button(new Point(165,18), new Size(135,92), offTxt);
  setBtn = new Button(new Point(17,129), new Size(135,92), setTxt);

  //Serial.println("Button created");
  //delay(50);
  //fore, back, pressed, text
  onBtn->setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);
  offBtn->setColors(VGA_RED, VGA_RED, VGA_MAROON, VGA_WHITE);
  setBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_NAVY, VGA_WHITE);

  //Serial.println("colors set");
  //delay(50);

  gui->addWidget(onBtn);
  gui->addWidget(offBtn);
  gui->addWidget(setBtn);

  //Serial.println("Widget added");
  //delay(50);

  gui->draw();

}

void ReflowView::DrawFlowPage()
{
  gui->clear();

  //char * onTxt = "ON";
  char * offTxt = "STOP";
  //char * setTxt = "SETTINGS";
  //onBtn = new Button(new Point(17,18), new Size(125,92), onTxt);

  char * tmpLblTxt = "%4.2f C";

  wantedTempLbl = new Label(new Point(167, 40), tmpLblTxt);
  realTempLbl = new Label(new Point(167, 80), tmpLblTxt);
  wantedTempDesLbl = new Label(new Point(20, 40), wantedLblTxt);
  realTempDesLbl = new Label(new Point(20, 80), realLblTxt);

  offBtn = new Button(new Point(93,129), new Size(135,92), offTxt);
  //Serial.println("Button created");
  //delay(50);
  //fore, back, pressed, text
  //onBtn->setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);
  offBtn->setColors(VGA_RED, VGA_RED, VGA_MAROON, VGA_WHITE);
  wantedTempLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  realTempLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  wantedTempDesLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  realTempDesLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);

  wantedTempLbl->addBinding((void*)wantedTemp, FLOAT);
  realTempLbl->addBinding((void*)realTemp, FLOAT);
  wantedTempDesLbl->addBinding((void*)&wantedLblTxt, FLOAT);
  realTempDesLbl->addBinding((void*)&realLblTxt, FLOAT);
  //Serial.println("colors set");
  //delay(50);

  //gui->addWidget(onBtn);
  gui->addWidget(offBtn);
  gui->addWidget(wantedTempLbl);
  gui->addWidget(realTempLbl);
  gui->addWidget(wantedTempDesLbl);
  gui->addWidget(realTempDesLbl);

  //gui->addWidget(setBtn);

  //Serial.println("Widget added");
  //delay(50);

  gui->draw();

}

void ReflowView::DrawSetPage()
{
  gui->clear();




}

void ReflowView::Update()
{
  //Serial.println("Update ui in reflowview");
  //delay(10);
  gui->update();
}
