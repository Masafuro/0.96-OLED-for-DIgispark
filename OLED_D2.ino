#include <TinySSD1306.h>
#include <Wire.h>

void setup()   {
  display.ssd1306_begin();  // initialize with the I2C addr 0x3C (for the 128x64)
  randomSeed(analogRead(0));
  display.ssd1306_setpos(0,0);
}

void loop() {
  int width = 128;
  int height = 32;
  int i,j,k;
  int w,b,column;
  w = 10;
  b = 8;
  column = 8;
  int D = B00000001;
  int x0,y0;
  x0=0;
  y0=0;

 display.ssd1306_fill_area();
 for(k=0;k<column;k++){
  for(j=0;j<b;j++){
    display.ssd1306_setpos(0,k);
    for(i=0;i<width;i++){
      display.ssd1306_data(D);
      delay(w);
    }
    D = D * 2 + 1;
  }
  D = B00000001;
 }
    
}
