#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "SmileDetector.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
     ofVideoGrabber cam;
    
  
    SmileDetector smile;
    
    
        bool findSmileFlg;
    
    ofVideoPlayer movLevel1, movLevel2, movLevel3, movLevel4, movLevel5, movLevel6;
    ofImage start, thank, count1, count2, count3,b_push;
    ofTrueTypeFont font;
		
};
