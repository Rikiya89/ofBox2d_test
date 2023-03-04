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
    ofSetColor(31, 127, 255,100);//circle's color 1 setting
    ofCircle(0, 0, radius);//draw a circle's 1
    ofSetColor(31, 127, 255,200);//circle's 2 color setting
    ofCircle(0, 0, radius * 0.7);
    ofPopMatrix();//back to coordinate
}
