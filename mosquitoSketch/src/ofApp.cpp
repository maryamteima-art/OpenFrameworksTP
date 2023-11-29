#include "ofApp.h"

//void ofApp::setup() {
//    ofSetFullscreen(true);  // Set to fullscreen
//    ofHideCursor();  // Hide the cursor
//
//    // Initialize mosquitoes at random positions
//    for (int i = 0; i < 10; ++i) {
//        mosquitoPositions.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//    }
//}

void ofApp::setup() {
    ofSetFullscreen(true);  // Set to fullscreen
    ofHideCursor();  // Hide the cursor

    // Initialize mosquitoes at random positions
    for (int i = 0; i < 10; ++i) {
        mosquitoPositions.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}

void ofApp::mousePressed(int x, int y, int button) {
    mousePosition.set(x, y);

    // Check for mosquito hits
    auto it = std::remove_if(mosquitoPositions.begin(), mosquitoPositions.end(),
        [&](const ofPoint& mosquito) {
            return ofDist(mousePosition.x, mousePosition.y, mosquito.x, mosquito.y) < 30;
        });

    mosquitoPositions.erase(it, mosquitoPositions.end());
}



float respawnTimer = 0;  // Timer to respawn mosquitoes
float respawnInterval = 2;  // Time interval in seconds for respawn

void ofApp::update() {
    respawnTimer += ofGetLastFrameTime();

    // Check if it's time to respawn mosquitoes
    if (respawnTimer > respawnInterval) {
        // Respawn mosquitoes at random positions
        mosquitoPositions.clear();  // Clear existing mosquitoes
        for (int i = 0; i < 10; ++i) {
            mosquitoPositions.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }

        // Reset the timer
        respawnTimer = 0;
    }
}




void ofApp::draw() {
    ofBackground(255);  // Set background color to white

    // Draw mosquitoes
    ofSetColor(0, 255, 0);  // Set color to green
    for (const auto& mosquito : mosquitoPositions) {
        ofDrawCircle(mosquito, 20);  // Draw a circle for each mosquito
    }

    // Draw hand cursor
    ofSetColor(255, 0, 0);  // Set color to red
    ofDrawCircle(mousePosition, 20);  // Draw a circle for the hand cursor
}

void ofApp::mouseMoved(int x, int y) {
    mousePosition.set(x, y);
}