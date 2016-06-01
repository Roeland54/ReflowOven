#include "ReflowView.h"

typedef void (ReflowView::*TouchCallbackPointer)(Widget*);
char * wantedLblTxt = "Wanted :";
char * realLblTxt = "Actual :";
char * Txt1 = "Soak ramp:";
char * Txt2 = "Soak time:";
char * Txt3 = "Soak temp:";
char * Txt4 = "Flow ramp:";
char * Txt5 = "Refl. temp";
char * Txt6 = "Refl. time";

double * Txt7;
double * Txt8;
double * Txt9;
double * Txt10;
double * Txt11;
double * Txt12;

ReflowView::ReflowView()
{

}

ReflowView::ReflowView(
    ClickedCallbackPointer press,
   ClickedCallbackPointer release,
   float *wantedTemp,
   float *realTemp,
   ReflowCurveSettings *curve)
{

  tft = new UTFT(MODEL, RS, WR, CSS, RST);
  //Serial.println("Starting up...");



  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  //Serial.println("Running");
  touch = new UTouch(A, B, C, D, E);

  gui = new GUI(tft, touch, press, release);
  this->wantedTemp = wantedTemp;
  this->realTemp = realTemp;

  Txt7 = &(curve->rtsTempPerSec);
  Txt8 = &(curve->soakTime);
  Txt9 = &(curve->soakTemp);
  Txt10 = &(curve->rtpTempPerSec);
  Txt11 = &(curve->reflowMaxTemp);
  Txt12 = &(curve->reflowTime);

  tft->InitLCD();
  tft->clrScr();
  tft->fillScr(VGA_WHITE);

  touch->InitTouch();
  touch->setPrecision(PREC_MEDIUM);

  DrawStartupPage();
}


void ReflowView::pressCallBack(Widget * _widget)
{
  //Serial.println("press");
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
    DrawSetPage();
  }
  else if (_widget == minRamp1Btn)
  {
    *Txt7 -= 0.1;
  }
  else if (_widget == plusRamp1Btn)
  {
    *Txt7 += 0.1;
  }
  else if (_widget == minSoakTimeBtn)
  {
    *Txt8 -= 2;
  }
  else if (_widget == plusSoakTimeBtn)
  {
    *Txt8 += 2;
  }
  else if (_widget == minSoakTempBtn)
  {
    *Txt9 -= 1;
  }
  else if (_widget == plusSoakTempBtn)
  {
    *Txt9 += 1;
  }
  else if (_widget == minRamp2Btn)
  {
    *Txt10 -= 0.1;
  }
  else if (_widget == plusRamp2Btn)
  {
    *Txt10 -= 0.1;
  }
  else if (_widget == minReflowTempBtn)
  {
    *Txt11 -= 1;
  }
  else if (_widget == plusReflowTempBtn)
  {
    *Txt11 += 1;
  }
  else if (_widget == minReflowTimeBtn)
  {
    *Txt12 -= 2;
  }
  else if (_widget == plusReflowTimeBtn)
  {
    *Txt12 += 2;
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

  char * offTxt = "<-";
  char * minTxt = "-";
  char * plusTxt = "+";

  ramp1Lbl = new Label(new Point(3, 20), Txt1);
  soakTimeLbl =  new Label(new Point(3, 50), Txt2);
  soakTempLbl =  new Label(new Point(3, 80), Txt3);
  ramp2Lbl =  new Label(new Point(3, 110), Txt4);
  reflowTempLbl =  new Label(new Point(3, 140), Txt5);
  reflowTimeLbl =  new Label(new Point(3, 170), Txt6);

  char * tmpLblTxt = "%4.1f";

  ramp1ValLbl = new Label(new Point(200, 20), tmpLblTxt);
  soakTimeValLbl =  new Label(new Point(200, 50), tmpLblTxt);
  soakTempValLbl =  new Label(new Point(200, 80), tmpLblTxt);
  ramp2ValLbl =  new Label(new Point(200, 110), tmpLblTxt);
  reflowTempValLbl =  new Label(new Point(200, 140), tmpLblTxt);
  reflowTimeValLbl =  new Label(new Point(200, 170), tmpLblTxt);

  offBtn = new Button(new Point(200,200), new Size(50,25), offTxt);
  minRamp1Btn = new Button(new Point(170,15), new Size(25,25), minTxt);
  minSoakTimeBtn = new Button(new Point(170,45), new Size(25,25), minTxt);
  minSoakTempBtn = new Button(new Point(170,75), new Size(25,25), minTxt);
  minRamp2Btn = new Button(new Point(170,105), new Size(25,25), minTxt);
  minReflowTempBtn = new Button(new Point(170,135), new Size(25,25), minTxt);
  minReflowTimeBtn = new Button(new Point(170,165), new Size(25,25), minTxt);

  plusRamp1Btn = new Button(new Point(285,15), new Size(25,25), plusTxt);
  plusSoakTimeBtn = new Button(new Point(285,45), new Size(25,25), plusTxt);
  plusSoakTempBtn = new Button(new Point(285,75), new Size(25,25), plusTxt);
  plusRamp2Btn = new Button(new Point(285,105), new Size(25,25), plusTxt);
  plusReflowTempBtn = new Button(new Point(285,135), new Size(25,25), plusTxt);
  plusReflowTimeBtn = new Button(new Point(285,165), new Size(25,25), plusTxt);


  offBtn->setColors(VGA_RED, VGA_RED, VGA_MAROON, VGA_WHITE);
  minRamp1Btn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  minSoakTimeBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  minSoakTempBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  minRamp2Btn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  minReflowTempBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  minReflowTimeBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);

  plusRamp1Btn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  plusSoakTimeBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  plusSoakTempBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  plusRamp2Btn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  plusReflowTempBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);
  plusReflowTimeBtn->setColors(VGA_BLUE, VGA_BLUE, VGA_BLUE, VGA_WHITE);

  ramp1Lbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  soakTempLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  soakTimeLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  ramp2Lbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  reflowTimeLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  reflowTempLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);

  ramp1ValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  soakTempValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  soakTimeValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  ramp2ValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  reflowTimeValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);
  reflowTempValLbl->setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);

  ramp1Lbl->addBinding((void*)&Txt1, FLOAT);
  soakTimeLbl->addBinding((void*)&Txt2, FLOAT);
  soakTempLbl->addBinding((void*)&Txt3, FLOAT);
  ramp2Lbl->addBinding((void*)&Txt4, FLOAT);
  reflowTempLbl->addBinding((void*)&Txt5, FLOAT);
  reflowTimeLbl->addBinding((void*)&Txt6, FLOAT);

  ramp1ValLbl->addBinding((void*)Txt7, DOUBLE);
  soakTimeValLbl->addBinding((void*)Txt8, DOUBLE);
  soakTempValLbl->addBinding((void*)Txt9, DOUBLE);
  ramp2ValLbl->addBinding((void*)Txt10, DOUBLE);
  reflowTempValLbl->addBinding((void*)Txt11, DOUBLE);
  reflowTimeValLbl->addBinding((void*)Txt12, DOUBLE);

  gui->addWidget(offBtn);
  gui->addWidget(minRamp1Btn);
  gui->addWidget(minSoakTimeBtn);
  gui->addWidget(minSoakTempBtn);
  gui->addWidget(minRamp2Btn);
  gui->addWidget(minReflowTempBtn);
  gui->addWidget(minReflowTimeBtn);



  gui->addWidget(ramp1Lbl);
  gui->addWidget(soakTempLbl);
  gui->addWidget(soakTimeLbl);
  gui->addWidget(ramp2Lbl);
  gui->addWidget(reflowTimeLbl);
  gui->addWidget(reflowTempLbl);

  gui->addWidget(ramp1ValLbl);
  gui->addWidget(soakTempValLbl);
  gui->addWidget(soakTimeValLbl);
  gui->addWidget(ramp2ValLbl);
  gui->addWidget(reflowTimeValLbl);
  gui->addWidget(reflowTempValLbl);

  gui->addWidget(plusRamp1Btn);
  gui->addWidget(plusSoakTimeBtn);
  gui->addWidget(plusSoakTempBtn);
  gui->addWidget(plusRamp2Btn);
  gui->addWidget(plusReflowTempBtn);
  gui->addWidget(plusReflowTimeBtn);

  //Serial.println("Widget added");
  //delay(50);
  gui->draw();

}

void ReflowView::Update()
{
  //Serial.println();
  //delay(10);

  gui->update();
}
