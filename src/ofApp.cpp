#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::makeButtons()
{
    int bW = 60;
    int bH = 25;

    clear.set(10, 10, bW, bH);
    save.set(10+bW+5, 10, bW, bH);
    invert.set(10+((bW*2)+10), 10, bW, bH);
    fillPolygon.set(10+((bW*3)+15), 10, bW, bH);
    nextPoly.set(10+((bW*4)+20),10,bW,bH);
    clearAll.set(10+((bW*5)+25), 10, bW+20, bH);
    increaseLineSize.set(10+((bW*6)+55), 10, bW, bH);
    decreaseLineSize.set(10+((bW*7)+65), 10, bW, bH);
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
    
    makeButtons();
    
    invertcolor = false;
    fillpoly = false;
    lineSize = 5;
    counter = 0;
    lastTagNumber = 0;
}
//--------------------------------------------------------------
void ofApp::update()
{
    
}
//--------------------------------------------------------------
void ofApp::draw()
{
    
    if (invertcolor) {
        ofBackground(0, 0, 0);
    }
    else {
        ofBackground(255, 255, 255);
    }
    ofFill();
    ofSetColor(255,0,0);
    ofRectRounded(clear, 8);
    
    ofSetColor(255,0,0);
    ofRectRounded(clearAll, 8);
    
    ofSetColor(0,150,255);
    ofRectRounded(save, 8);
    
    ofSetColor(255, 0, 255);
    ofRectRounded(invert, 8);

    ofSetColor(0, 255, 105);
    ofRectRounded(fillPolygon ,8);
    
    ofSetColor(100, 100, 255);
    ofRectRounded(nextPoly, 8);
    
    ofSetColor(100, 200, 255);
    ofRectRounded(increaseLineSize, 8);
    
    ofSetColor(100, 200, 255);
    ofRectRounded(decreaseLineSize, 8);
    
    ofSetColor(0);
    int offsetY = 15;
    ofDrawBitmapString("Clear",clear.x+5,clear.y+offsetY);
    ofDrawBitmapString("Clear All",clearAll.x+5,clearAll.y+offsetY);
    ofDrawBitmapString("Save",save.x+5,save.y+offsetY);
    ofDrawBitmapString("Invert",invert.x+5,invert.y+offsetY);
    ofDrawBitmapString("Fill",fillPolygon.x+5,fillPolygon.y+offsetY);
    ofDrawBitmapString("Next",nextPoly.x+5,nextPoly.y+offsetY);
    ofDrawBitmapString("Line +",increaseLineSize.x+5,increaseLineSize.y+offsetY);
    ofDrawBitmapString("Line -",decreaseLineSize.x+5,decreaseLineSize.y+offsetY);
    
    if (lines.size() > 0) {
        for(int i = 0; i < lines.size(); i++) {
            lines[i].setFill(fillpoly);
            lines[i].setInverse(invertcolor);
            lines[i].setLineSize(lineSize);
            lines[i].draw();
        }
    }
    
    p.setFill(fillpoly);
    p.setInverse(invertcolor);
    p.setLineSize(lineSize);
    p.draw();
    
    
    
    if (invertcolor) {
        ofSetColor(255);
    }
    else {
        ofSetColor(0);
    }
    ofCircle(mouseX, mouseY, 15);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT)
    {
        p.addPoint(ofVec3f(x,y,0));
    }
    else if (button == OF_MOUSE_BUTTON_RIGHT)
    {
        if(clear.inside(x, y)) {
            p.clear();
        }
        else if(clearAll.inside(x, y)) {
            lines.clear();
        }
        else if(decreaseLineSize.inside(x, y)) {
            lineSize--;
        }
        else if(increaseLineSize.inside(x, y)) {
            lineSize++;
        }
        else if(save.inside(x, y)) {
            string timestamp = ofGetTimestampString();
            ofSaveScreen("mapping-"+timestamp+".png");
            xml.clear();
            lastTagNumber = 0;
            
            if (lines.size() > 0) {
                for (int i = 0; i < lines.size(); i++) {
                    xml.addTag(ofToString(i));
                    if (xml.pushTag(ofToString(i))) {
                        xml.addTag("pts");
                        if(xml.pushTag("pts")) {
                            if (lines[i].getPts().size() > 0) {
                                for (int p = 0; p < lines[i].getPts().size(); p++) {
                                    xml.setValue("x", lines[i].getPts()[p].x,p);
                                    xml.setValue("y", lines[i].getPts()[p].y,p);
                                }
                            }
                        }
                        xml.popTag();
                    }
                    xml.popTag();
                }
            }
            xml.save("mapping-"+timestamp+".xml");
        }
        else if(invert.inside(x, y)){
            invertcolor = !invertcolor;
        }
        else if(fillPolygon.inside(x, y)) {
            fillpoly = !fillpoly;
        }
        else if(nextPoly.inside(x,y)) {
            p.addID(counter);
            lines.push_back(p);
            p.clear();
            counter++;
        }
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
    
}
