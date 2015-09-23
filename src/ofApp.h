#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

class polys {
public:
    //--------------------------------------------------------------
    void addID(int pid) {
        _id = pid;
    }
    //--------------------------------------------------------------
    void addPoint(ofVec3f pos) {
        clickPts.push_back(pos);
    }
    //--------------------------------------------------------------
    void clear() {
        clickPts.clear();
    }
    //--------------------------------------------------------------
    void setInverse(bool invert) {
        inverts = invert;
    }
    //--------------------------------------------------------------
    void setFill(bool _fill) {
        fill = _fill;
    }
    //--------------------------------------------------------------
    void draw(){
        ofPushStyle();
        ofSetLineWidth(5);
        if (fill) {
            ofFill();
        }
        else {
            ofNoFill();
        }
        
        if (inverts) {
            ofSetColor(255,255,255);
        }
        else {
            ofSetColor(0, 0, 0);
        }
        ofBeginShape();
        for (int i = 0; i < clickPts.size(); i++) {
            ofVertex(clickPts[i].x, clickPts[i].y);
            
        }
        ofEndShape(true);
        ofPopStyle();
        
    }
    //--------------------------------------------------------------
    vector <ofVec3f> getPts() {
        return clickPts;
    }
    //--------------------------------------------------------------
    int getID() {
        return _id;
    }
    
protected:
    vector <ofVec3f> clickPts;
    bool inverts;
    bool fill;
    int _id;
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        // Silly Line objects
        vector<polys> lines;
    
        // Silly Lines
        polys p;
    
        // Buttons
        ofRectangle save;
        ofRectangle clear;
        ofRectangle clearAll;
        ofRectangle invert;
        ofRectangle fillPolygon;
        ofRectangle nextPoly;
    
        bool invertcolor;
        bool fillpoly;
        int counter;
    
        int lastTagNumber;
    
            ofxXmlSettings xml;
};

