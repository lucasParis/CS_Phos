#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ledsOutput.setup(9003);//arguments: udp port and udp address
}

//--------------------------------------------------------------
void ofApp::update(){

    //test pattern
    for (int x = 0; x < LED_MATRIX_WIDTH; x++) {
        for (int y = 0; y < LED_MATRIX_HEIGHT; y++) {
            LedMatrix2D[x][y] = pow(sin(ofGetElapsedTimef() * 3.14 + (3.14 * float(y)/LED_MATRIX_HEIGHT) + (3.14 * float(x)/LED_MATRIX_WIDTH)) * 0.5 + 0.5, 3) * 100;
        }
    }
    
    ledsOutput.sendData(LedMatrix2D);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //draw test pattern to screen
    float rectW = float(ofGetWidth())/LED_MATRIX_HEIGHT;
    float rectH = float(ofGetHeight())/LED_MATRIX_WIDTH;
    for (int y = 0; y < LED_MATRIX_WIDTH; y++) {
        for (int x = 0; x < LED_MATRIX_HEIGHT; x++) {
            ofFill();
            ofSetColor(LedMatrix2D[y][x]);
            ofDrawRectangle(x * rectW, y*rectH, rectW, rectH);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
