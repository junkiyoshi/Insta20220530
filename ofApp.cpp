#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	auto radius = 300;

	for (int z = -300; z <= 300; z += 300) {

		for (auto deg = 0; deg < 360; deg += 10) {

			auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);

			ofPushMatrix();
			ofTranslate(location);
			ofRotateZ(deg);

			ofRotateY(deg + ofGetFrameNum());

			ofFill();
			ofSetColor(0);
			ofDrawBox(45);

			ofNoFill();
			ofSetColor(255);
			ofDrawBox(45);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}