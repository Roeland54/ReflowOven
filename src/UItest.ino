#include "ui/UI.h"
#include <UTFT.h>

//UTFT(model, sda, scl, cs, rst, rs)
UTFT tft(ILI9341_S5P,11,13,8,9,10);

UI ui(&tft);

char * btnTxt = "BUTTON";
char * lblTxt = "Label.";
char * txtTxt = "Text!";
char * chkTxt = "Check?";
char * grpTxt = "Group";

Label lbl(new Point(100,90), lblTxt);
Button btn(new Point(10,10), new Size(100,30), btnTxt);
TextBox txt(new Point(50,50), new Size(60,30), txtTxt);
CheckBox chk(new Point(10,10), chkTxt);
CheckBox chk2(new Point(10,25), chkTxt);
ProgressBar prgs(new Point(10,140), new Size(300, 20));
Panel pnl(new Point(160, 10), new Size(150, 120));
Label pnlLbl(new Point(10,10), lblTxt);
ProgressBar prgs2(new Point(10,100), new Size(130, 10));
GroupBox grp(new Point(10,170), new Size(100,60), grpTxt);

void setup()
{
	//Dit dient als achtergrondverlichting van de display, niet achter kijken
	pinMode(6, OUTPUT);
	digitalWrite(6, 255);

	//Instellingen van display
	tft.InitLCD(LANDSCAPE);
	tft.clrScr();
	tft.fillScr(VGA_SILVER);

	//Een aantal instellingen van de widgets
	chk2.setCheck(true);
	prgs.setPercentage(33);
	prgs2.setPercentage(80);

	//Hier worden alle widgets toegevoegd aan de UI.
	//Een betere practice zou misschien zijn om een panel te maken de grootte van de display
	//Maar momenteel is dat nog niet echt nodig
	//Wat handig zou zijn, is een screenmanager, misschien dat ik hier nog voor kijk
	ui.addWidget(&lbl);
	ui.addWidget(&btn);
	ui.addWidget(&txt);
	ui.addWidget(&prgs);
	ui.addWidget(&pnl);
	pnl.addChild(&pnlLbl); //addChild pas uitvoeren na ui.addWidget! ervoor is de tft pointer nog niet gekend
	pnl.addChild(&prgs2); //Zelfde als hierboven
	ui.addWidget(&grp);
	grp.addChild(&chk);	//Weer zelfde als hierboven
	grp.addChild(&chk2); //En nog een keer

	//En uiteindelijk tekenen we dit één keer
	ui.draw();
}

void loop()
{

}
