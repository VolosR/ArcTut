#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int x=85;
int y=100;
int r1=75;
int r2=60;
int a1=0;
int a2=270;

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
    sprite.drawSmoothArc(x, y, r1, r2, a1, a2, TFT_MAGENTA, TFT_BLACK);

    for(int i=0;i<10;i++)
    sprite.drawSmoothArc(x, 230, 52, 32, (i*36), ((i+1)*36)-6, TFT_SILVER, TFT_BLACK);

    for(int i=0;i<5;i++)
    sprite.drawSmoothArc(x, 230, 52, 32, (i*36), ((i+1)*36)-6, TFT_MAGENTA, TFT_BLACK);
    
    sprite.pushSprite(0,0);

 
  }

void loop() {
  draw();
}
