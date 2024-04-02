#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

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
    sprite.pushSprite(0,0);
  }

void loop() {
  draw();
}