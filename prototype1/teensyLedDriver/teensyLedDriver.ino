#include <FastLED.h>

#define NUM_LEDS 312
//#define COLS 76
#define COLS 52
#define ROWS 6

CRGB leds[NUM_LEDS];
int indexcount;

float lastOutputTime;

void setup() {
  lastOutputTime = 0;
  Serial.begin(1382400);
  FastLED.addLeds<APA102, BGR>(leds, NUM_LEDS);

}

void loop() {

  while (Serial.available() > 0) {
    int incomingByte = Serial.read();
    if (incomingByte == 255)
    {
      indexcount = 0;
    }
    else
    {
      int value = incomingByte;
      if (indexcount < NUM_LEDS)
      {
          leds[indexcount].red = value;
          leds[indexcount].green = value;
          leds[indexcount].blue = value;
      }
      indexcount++;
    }
  }

  //  String incoming = Serial.readStringUntil('\n');


  //  if (incoming.length() > 2)
  //  {
  //    //    Serial.println("got");
  //    //    Serial.println(incoming);
  //    String indexS = getValue(incoming, ' ', 0);
  //    int index = indexS.toInt();
  //    //    String yval = getValue(incoming, ' ', 1);
  //    String value = getValue(incoming, ' ', 1);
  //    //    int x = xval.toInt();
  //    //    int y = yval.toInt();
  //    int val = value.toInt();
  //    //    int oddRow = x % 2;
  //    //    int index = 0;
  //    //    if (oddRow == 0)
  //    //    {
  //    //      index = (x * COLS) + y;
  //    //    }
  //    //    else if (oddRow == 1)
  //    //    {
  //    //      index = ((x + 1) * COLS) - y - 1;
  //    //    }
  //    if (index < NUM_LEDS)
  //    {
  //      leds[index].red = val ;
  //      leds[index].green = val ;
  //      leds[index].blue = val ;
  //      //      Serial.println(val * 255);
  //    }
  //
  //  }
  if (millis() - lastOutputTime   > 15)
  {
    FastLED.show();


    lastOutputTime = millis();
  }
}

