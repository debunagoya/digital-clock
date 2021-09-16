#include <FastLED.h>
#include <DS3232RTC.h>
#define numberOfLEDs 168
#define controlPin 5
#define photocellPin 7
CRGB leds[numberOfLEDs];
  
int rb[] = {0,1,3,4,5,6,7,8,9}; // 右下
int bb[] = {0,2,3,5,6,8,9};     // 下
int lb[] = {0,2,6,8};           // 左下
int lu[] = {0,4,5,6,8,9};       // 左上
int uu[] = {0,2,3,5,6,7,8,9};   // 上
int ru[] = {0,1,2,3,4,7,8,9};   // 右上
int cc[] = {2,3,4,5,6,8,9};     // 中央
int thisLED = 0;

void setup() {
  // 時刻設定
  //  setTime(15, 7, 0, 27, 6, 2021);
  //  RTC.set(now());
  
  Serial.begin(9600);
  setSyncProvider(RTC.get);
  pinMode(photocellPin, INPUT); 
  FastLED.addLeds<WS2812B, controlPin, GRB>(leds, numberOfLEDs);
}

bool jbar(int a, int *b, int n) {
  for (int i=0; i<n; i++){
    if (a == b[i]) {
      return true;
    }
  }
  return false;
}

void lighton() {
  if ( digitalRead(photocellPin) == 0 ) { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; }
  else if ( 18 <= hour() || hour() < 6 ) { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 255; }
  else if ( 6 <= hour()  && hour() < 18 ) { leds[thisLED].r = 0; leds[thisLED].g = 255; leds[thisLED].b = 0; }
}

void loop() { 
  int bar = 1; // 点灯番号 

  for (thisLED=0; thisLED < numberOfLEDs; thisLED++) {
    if (thisLED % 6 == 0 and thisLED != 0) {
      bar++;
    }
    switch(bar) {
      // 4桁目
      case  1: if (jbar(minute()%10, rb, 9)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  2: if (jbar(minute()%10, bb, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  3: if (jbar(minute()%10, lb, 4)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  4: if (jbar(minute()%10, cc, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  5: if (jbar(minute()%10, ru, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  6: if (jbar(minute()%10, uu, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  7: if (jbar(minute()%10, lu, 6)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
               
      // 3桁目
      case  8: if (jbar(minute()/10, rb, 9)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case  9: if (jbar(minute()/10, bb, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 10: if (jbar(minute()/10, lb, 4)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 11: if (jbar(minute()/10, cc, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 12: if (jbar(minute()/10, ru, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 13: if (jbar(minute()/10, uu, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 14: if (jbar(minute()/10, lu, 6)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
               
      // 2桁目
      case 15: if (jbar(hour()%10, rb, 9)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 16: if (jbar(hour()%10, bb, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 17: if (jbar(hour()%10, lb, 4)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 18: if (jbar(hour()%10, cc, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 19: if (jbar(hour()%10, ru, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 20: if (jbar(hour()%10, uu, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 21: if (jbar(hour()%10, lu, 6)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
               
      // 1桁目
      case 22: if (jbar(hour()/10, rb, 9)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 23: if (jbar(hour()/10, bb, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 24: if (jbar(hour()/10, lb, 4)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 25: if (jbar(hour()/10, cc, 7)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 26: if (jbar(hour()/10, ru, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 27: if (jbar(hour()/10, uu, 8)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
      case 28: if (jbar(hour()/10, lu, 6)) { lighton(); } else { leds[thisLED].r = 0; leds[thisLED].g = 0; leds[thisLED].b = 0; } break;
    }
  }

  FastLED.show();
  delay(1000);
}
