#include <TFT_eSPI.h>
#include "Noto.h"
#include "NotoBig.h"
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int x=85;
int y=100;
int r1=75;
int r2=60;
int a1=0;
int a2=270;
unsigned short c1=TFT_ORANGE;
unsigned short c2=TFT_BLACK;
unsigned short c3=0x09CB;

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  sprite.createSprite(170,320);

     //brightness
     ledcSetup(0, 10000, 8);
     ledcAttachPin(38, 0);
     ledcWrite(0, 160);

     
}

void draw()
  {
    sprite.fillSprite(TFT_BLACK); 
    sprite.drawSmoothArc(x, y, r1, r2, a1, a2, c1, c2);
    sprite.fillSmoothCircle(x, y, 5, TFT_SILVER);

    sprite.setTextDatum(0);
    sprite.loadFont(Noto);
    sprite.setTextColor(TFT_WHITE,TFT_BLACK);
    sprite.drawString("(x,y)",x+8,y+5);
    sprite.drawString("r1",40,y-16);
    sprite.drawString("r2",x+6,y-28);

    sprite.setTextColor(TFT_SILVER,TFT_BLACK);
    sprite.drawString("0'",x,y+80);
    sprite.drawString("180'",x-14,6);
    sprite.unloadFont();


    sprite.fillRect(10,y-1,r1,2,TFT_SILVER);
    sprite.fillSmoothCircle(10, y, 3, TFT_SILVER);

    sprite.fillRect(x-1,40,2,r2,TFT_SILVER);
    sprite.fillSmoothCircle(x-1, 40, 3, TFT_SILVER);

    for(int i=0;i<12;i++)
    sprite.drawSmoothArc(x, y+154, 52, 32,i*30, ((i+1)*30)-9, c3, c2);

     for(int i=0;i<8;i++)
    sprite.drawSmoothArc(x, y+154, 52, 32,i*30, ((i+1)*30)-9, c1, c2);

    sprite.fillSmoothCircle(x,y+154,26,c3);

    sprite.loadFont(NotoBig);
    sprite.setTextDatum(4);
    sprite.setTextColor(TFT_WHITE,c3);
    sprite.drawString("75",x,y+156);
    sprite.unloadFont();

    

    sprite.pushSprite(0,0);
  }

void loop() {
  draw();
}



