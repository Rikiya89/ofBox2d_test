#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();

    //setting Box2d
    box2d.init();//reset box2d world
    box2d.setGravity(0, 5);//setting gravity
    box2d.createBounds(0,0, ofGetWidth(), ofGetHeight()); //setting wall
    box2d.setFPS(30);//appear 30fps

    //add an obstacle
    for (int i = 0; i < 100; i++){
        auto r = make_shared<ofxBox2dRect>();
        float w = 2;
        float h = 2;
        float x = ofRandom(50,ofGetWidth() - 50);
        float y = ofRandom(50, ofGetHeight() - 50);
        r -> setup(box2d.getWorld(), x, y, w,h);
        rects.push_back(r);
    }

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

    for (int i = 0; i < rects.size(); i++) {
        ofSetColor(255, 63, 63);
        rects[i] -> draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //when type a "c" key, add a circle
    if (key == 'c') {
        float r = ofRandom(5,20); //setting radius
        auto c = make_shared<CustomCircle>();
        c->setPhysics(1.0, 0.8, 0.5);//physic parameter
        c->setup(box2d.getWorld(), mouseX, mouseY, r);
        circles.push_back(c);
    }

    //when type a "r" key, delete all of circles
    if (key == 'r') {
        for (int i = 0; i < circles.size(); i++){
            circles[i] -> destroy();
        }
        circles.clear();
    }
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
    //    float r = ofRandom(10,40);
    //    auto circle = make_shared<ofxBox2dCircle>();
    //    circle->setPhysics(1.0, 0.8, 0.5);
    //    circle->setup(box2d.getWorld(), mouseX, mouseY, r);
    //    circles.push_back(circle);
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
