//
//  CustomCircle.cpp
//  ofBox2d_test
//
//  Created by Ricky O'kawa on 2023/01/22.
//

#include "CustomCircle.h"

void CustomCircle::draw() {
    float radius = getRadius(); //get a radius
    ofPushMatrix();//change a coordinate
    ofTranslate(getPosition().x, getPosition().y);//move a coordinate to position
    ofFill();
    ofSetColor(255, 151, 255,100);//circle's color 1 setting
    ofDrawCircle(0, 0, radius);//draw a circle's 1
    ofSetColor(255, 153, 255,200);//circle's 2 color setting
    ofDrawCircle(0, 0, radius * 0.7);
    ofPopMatrix();//back to coordinate
}
