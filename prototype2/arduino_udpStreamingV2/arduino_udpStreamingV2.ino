

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#define UDP_TX_PACKET_MAX_SIZE 500
#include <FastLED.h>

#define NUM_LEDS 360// 36 leds * 10 boxes, number of leds per output (9 per pcb)
CRGB leds[9][NUM_LEDS];//holds the values of the leds for fastled output
#define RATE 3 // 3 seems like the ideal value, slowdown if glitches appear at the end of the strips but watchout for dropping FPS
float lastOutputTime;//used as a counter to limit the output rate to 60fps, when lastoutputtime is bigger then current time minus 16milliseconds, sends data to leds

//set teensy at 144 mhz


EthernetUDP Udp;
IPAddress ip(10, 10, 10, 11);//ip of the arduino's ethernet chip
const unsigned int inPort = 9003;//udp port for incoming data

byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//mac adress of the wiznet chips


void setup() {
  Serial.begin(115200);
  Ethernet.begin(mac, ip);
  Udp.begin(inPort);

   lastOutputTime = 0;
  //setup led outputs, port numbers and order tested, from the pcb schematic
  FastLED.addLeds<APA102, 5, 6, BGR, DATA_RATE_MHZ(RATE)>(leds[2], NUM_LEDS);
  FastLED.addLeds<APA102, 7, 8, BGR, DATA_RATE_MHZ(RATE)>(leds[1], NUM_LEDS);
  FastLED.addLeds<APA102, 25, 26, BGR, DATA_RATE_MHZ(RATE)>(leds[0], NUM_LEDS);
  FastLED.addLeds<APA102, 27, 28, BGR, DATA_RATE_MHZ(RATE)>(leds[5], NUM_LEDS);
  FastLED.addLeds<APA102, 29, 30, BGR, DATA_RATE_MHZ(RATE)>(leds[4], NUM_LEDS);
  FastLED.addLeds<APA102, 31, 32, BGR, DATA_RATE_MHZ(RATE)>(leds[3], NUM_LEDS);
  FastLED.addLeds<APA102, 0, 1, BGR, DATA_RATE_MHZ(RATE)>(leds[8], NUM_LEDS);
  FastLED.addLeds<APA102, 3, 4, BGR, DATA_RATE_MHZ(RATE)>(leds[7], NUM_LEDS);
  FastLED.addLeds<APA102, 19, 18, BGR, DATA_RATE_MHZ(RATE)>(leds[6], NUM_LEDS);

}

void loop() {
  // put your main code here, to run repeatedly:
  //  Serial.println("waiting");

  int packetSize = Udp.parsePacket();//check if incoming data is available
  if (packetSize) {
//    Serial.println("got");
    char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

    //reading udp
    // buffer to hold incoming packet
    //      for(int i = 0 ; i< UDP_TX_PACKET_MAX_SIZE; i++)
    //      {
    //        packetBuffer[i]= 0;
    //      }
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); //reading udp data into the buffer
    //        Serial.print("udppdppd!   ");
    //    IPAddress remote = Udp.remoteIP();
    //        Serial.print(packetSize);
    //        Serial.println(remote);

    int x = int(packetBuffer[0]);
//    Serial.println(x);
    for (int y = 0; y < 360; y++)
    {

      int value = int(packetBuffer[1+y]);
      leds[x][y].red = value;
      leds[x][y].green = value;
      leds[x][y].blue = value;
//      Serial.println(int(packetBuffer[i]));
    }


  }
//fastled output
  if (millis() - lastOutputTime   > 15)//check if it's been 15 milliseconds since last output (don't want to output too fast)
  {
//    for (int x = 0; x < 9; x++)//loop trough the 9 led strips outputs
//    {
//      for (int i = 0; i < 36; i++)//loop through the first 36 leds of the strip (change 36 to 386 for the 11 boxes)
//      {
//        int value = 0;
//        value = (x * 3 + int(millis() * 0.001 * 10)) % 36;//formula generates a pixel moving down the strip
//        value = (value == i) || (value == (i + 1));// double the pixel to get a group of 2 moving pixels
////        value = 1;// double the pixel to get a group of 2 moving pixels
//        //set led values (low brightness, multiply by 255 for full brightness
////        leds[x][i].red = int(value * 20);
////        leds[x][i].green =  int(value * 20);
////        leds[x][i].blue = int(value * 20);
//
//      }
//    }

    FastLED.show();//send led data to strips
    lastOutputTime = millis();//update time for output counter
  }

  
}
