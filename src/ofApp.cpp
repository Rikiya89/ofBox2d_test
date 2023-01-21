#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);

    //setting Box2d
    box2d.init();//reset box2d world
    box2d.setGravity(0, 5);//setting gravity
    box2d.createBounds(0,0, ofGetWidth(), ofGetHeight()); //setting wall
    box2d.setFPS(30);//appear 30fps
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < circles.size(); i++){
        ofFill();//fill
        ofSetColor(153, 153, 255);//setting color
        circles[i]->draw();//draw all of circles
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
    //when clicked screen, add a circle
    float r = ofRandom(10,40);
    auto circle = make_shared<ofxBox2dCircle>();
    circle->setPhysics(1.0, 0.8, 0.5);
    circle->setup(box2d.getWorld(), mouseX, mouseY, r);
    circles.push_back(circle);
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
