#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    vidGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240);
    grayImage.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    bLearnBakground = true;
    threshold = 100;

    //setting Box2d
    box2d.init();//reset box2d world
    box2d.setGravity(0, 1);//setting gravity
    box2d.createBounds(0,0, colorImg.width, colorImg.height); //setting wall
    box2d.setFPS(30);//appear 30fps
    box2d.checkBounds(true);

    //position 1000 circle
    static const int NUM = 1000;
    for (int i = 0; i < NUM; i++){
        auto circle = make_shared<CustomCircle>();
        circle->setPhysics(1.0, 0.8, 0.0);
        circle->setup(box2d.getWorld(), ofRandom(colorImg.width), ofRandom(colorImg.height), 3);
        circles.push_back(circle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //    update box2d
    box2d.update();

    //    check a new frame
    bool bNewFrame = false;

    //    check a last frame
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    //    if sentence for new frame
    if (bNewFrame) {
        colorImg.setFromPixels(vidGrabber.getPixels());

        grayImage = colorImg;

        if(bNewFrame == true) {
            grayBg = grayImage;
            bLearnBakground = false;
        }
    }

    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(threshold);
    countourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 10, false);

    // reset a circle
    for (int i = 0; i < contourCircles.size(); i++) {
        contourCircles[i]->destroy();
    }
    contourCircles.clear();
    //analyse blobs
    for (int i = 0; i < countourFinder.nBlobs; i++) {
        for (int j = 0; j < countourFinder.blobs[i].pts.size(); j += 4) {
            glm::vec2 pos = countourFinder.blobs[i].pts[j];
            auto circle = make_shared<ofxBox2dCircle>();
            circle->setup(box2d.getWorld(), pos.x, pos.y, 4);
            contourCircles.push_back(circle);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float ratioX = ofGetWidth() / 320;
    float ratioY = ofGetHeight() / 240;

    ofPushMatrix();

    ofScale((float)ofGetWidth() / (float)grayDiff.width, (float)ofGetHeight() / (float)grayDiff.height);
    ofSetColor(255, 255, 255);
    colorImg.draw(0, 0);
    countourFinder.draw();
//draw a circle's border
    ofNoFill();
    ofSetColor(255, 0, 0);
    for(int i = 0; i < contourCircles.size(); i++) {
        contourCircles[i]->draw();
    }
//    draw a Custom circle
    for (int i = 0; i < circles.size(); i++) {
        circles[i]->draw();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case' ':
            bLearnBakground = true;
            break;
        case '+':
            threshold++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold--;
            if (threshold < 0) threshold = 0;
            break;
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
