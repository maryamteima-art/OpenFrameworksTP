#pragma once

#include "ofMain.h"
class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);  // Add the mouseMoved method

private:
    ofPoint mousePosition;
    std::vector<ofPoint> mosquitoPositions;
};
//test