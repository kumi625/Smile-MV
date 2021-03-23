

#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "ofxCv.h"

using namespace ofxCv;
using namespace cv;


class SmileDetector {
public:
    
    
    ofRectangle roi;
    ofxCv::ObjectFinder faceFinder, smileFinder;
    
    void setup() {
        faceFinder.setup("haarcascade_frontalface_default.xml");
        faceFinder.setPreset(ofxCv::ObjectFinder::Accurate);
        faceFinder.setFindBiggestObject(true);
        smileFinder.setup("smiled_01.xml");
        smileFinder.setPreset(ofxCv::ObjectFinder::Sensitive);
        smileFinder.setMinNeighbors(200);//kore
    }
    
    template <class T>
    void update(T& img) {
        update(ofxCv::toCv(img));
    }
    
    void update(const cv::Mat& mat) {
        faceFinder.update(mat);
        if(faceFinder.size()) {
            roi = faceFinder.getObject(0);
            float lowerRatio = .35;
            roi.y += roi.height * (1 - lowerRatio);
            roi.height *= lowerRatio;
            cv::Mat faceMat(mat, ofxCv::toCv(roi));
            smileFinder.update(faceMat);
        }
    }
    
    void draw() const {
        faceFinder.draw();
        if(faceFinder.size()) {
            ofPushMatrix();
            ofTranslate(roi.position);
            smileFinder.draw();
            ofPopMatrix();
        }
    }
    bool getFaceFound() const {
        return faceFinder.size();
    }
    ofRectangle getFace() const {
        return faceFinder.getObject(0);
    }
    int getSmileAmount() const {
        if(faceFinder.size()) {
            return smileFinder.size();
        } else {
            return 0;
        }
    }
};


