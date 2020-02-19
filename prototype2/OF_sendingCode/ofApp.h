#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#define LED_MATRIX_WIDTH 9
#define LED_MATRIX_HEIGHT 360

//copy this class
class UdpLedOutput
{
public:
    void setup(int portLeds = 9003, string ipLeds = "10.10.10.11")
    {
        udpOut.Create();
        udpOut.Connect(ipLeds.c_str(),portLeds);
        udpOut.SetNonBlocking(true);
    }
    
    void sendData(unsigned char LedMatrix2D[LED_MATRIX_WIDTH][LED_MATRIX_HEIGHT])
    {
        for(int strip = 0; strip < LED_MATRIX_WIDTH; strip++)
        {
            int sizeOut = 1 + LED_MATRIX_HEIGHT;
            char dataOut[sizeOut];
            
            dataOut[0] = strip; //index 0 is the strip number
            
            for(int i = 0; i < sizeOut-1; i++)
            {
                dataOut[i+1] = LedMatrix2D[strip][i];
            }
            
            udpOut.Send(dataOut, sizeOut);
            usleep(200);
        }
    }
    ofxUDPManager udpOut;
    
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofxUDPManager udpOut;
    unsigned char LedMatrix2D[LED_MATRIX_WIDTH][LED_MATRIX_HEIGHT];

    
    UdpLedOutput ledsOutput;

};




