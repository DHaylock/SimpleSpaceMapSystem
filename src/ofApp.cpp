#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
    clear.set(10, 10, 50, 50);
    save.set(70, 10, 50, 50);
    invert.set(130, 10, 50, 50);
    fillPolygon.set(190, 10, 50, 50);
    nextPoly.set(250,10,50,50);
    clearAll.set(310, 10, 50, 50);
    invertcolor = false;
    fillpoly = false;
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
    
    
    if (lines.size() > 0) {
        for(int i = 0; i < lines.size(); i++) {
            lines[i].setFill(fillpoly);
            lines[i].setInverse(invertcolor);
            lines[i].draw();
        }
    }
    
    p.setFill(fillpoly);
    p.setInverse(invertcolor);
    p.draw();
    
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
    
    
    ofSetColor(0);
    ofDrawBitmapString("Clear",clear.x+5,clear.y+20);
    ofDrawBitmapString("Clear All",clearAll.x+5,clearAll.y+20);
    ofDrawBitmapString("Save",save.x+5,save.y+20);
    ofDrawBitmapString("Invert",invert.x+5,invert.y+20);
    ofDrawBitmapString("Fill",fillPolygon.x+5,fillPolygon.y+20);
    ofDrawBitmapString("Next",nextPoly.x+5,nextPoly.y+20);
    
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
