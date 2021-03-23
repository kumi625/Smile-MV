#include "ofApp.h"
#include <stdio.h>


int startTime, smileStartTime;
int c;
int lastC;
int flag = 0;
int countFlag = 0;
int countFlagStart = 0;
int loopflag = 0;



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(0,0,0);

    ofSetVerticalSync(true);
    ofSetFrameRate(10);
    cam.setup(1280,720);
    smile.setup();
    findSmileFlg = false;
    
    start.load("start.jpg");
    thank.load("thank.jpg");
    count1.load("count1.jpg");
    count2.load("count2.jpg");
    count3.load("count3.jpg");
    b_push.load("b_push.jpg");
    movLevel1.load("shukujo.mp4");
    movLevel1.setLoopState(OF_LOOP_NONE);
    movLevel2.load("inochi.mp4");
    movLevel2.setLoopState(OF_LOOP_NONE);
    movLevel3.load("june.mp4");
    movLevel3.setLoopState(OF_LOOP_NONE);
    movLevel4.load("melty.mp4");
    movLevel4.setLoopState(OF_LOOP_NONE);
    movLevel5.load("yomo.mp4");
    movLevel5.setLoopState(OF_LOOP_NONE);

    
    font.load("arial.ttf", 50);

}

//--------------------------------------------------------------
void ofApp::update(){

    

    //三秒カウント
    if(flag == 1){
        int newtime = ofGetSeconds();
        if(newtime < startTime){
            if(newtime+60 - startTime == 2){
                countFlagStart = 1;
            }else if(newtime+60 - startTime == 3){
                countFlagStart = 2;
            }else if(newtime+60 - startTime == 4){
                countFlagStart = 3;
            }
        }else if(startTime < newtime){
            if(newtime - startTime == 2){
                countFlagStart = 1;
            }else if(newtime - startTime == 3){
                countFlagStart = 2;
            }else if(newtime - startTime == 4){
                countFlagStart = 3;
            }
        }
    }
    
    // 五秒カウント
    if(flag == 2){
        cam.update();
        smile.update(cam);
        int time = ofGetSeconds();
        if(smile.getSmileAmount()) {
            findSmileFlg = true;
            c++;
        }
        if(time < smileStartTime){
            if(time+60 - smileStartTime == 1){
                countFlag = 1;
            }else if(time+60 - smileStartTime == 2){
                countFlag = 2;
            }else if(time+60 - smileStartTime == 3){
                countFlag = 3;
            }else if(time+60 - smileStartTime == 4){
                countFlag = 4;
            }
            if(time+60 - smileStartTime == 5){
                countFlag = 5;
                lastC = c;
                std::cout << lastC << endl;
                smileStartTime = 100;
                if(lastC < 10){
                    flag = 3;
                }else if(lastC < 20){
                    flag = 4;
                }else if(lastC < 30){
                    flag = 5;
                }else if(lastC < 40){
                    flag = 6;
                }else {
                    flag = 7;
                }
            }
        }else if(smileStartTime < time){
            if(time - smileStartTime == 1){
                countFlag = 1;
            }else if(time - smileStartTime == 2){
                countFlag = 2;
            }else if(time - smileStartTime == 3){
                countFlag = 3;
            }else if(time - smileStartTime == 4){
                countFlag = 4;
            }
            if(time - smileStartTime == 5){
                countFlag = 5;
                lastC = c;
                std::cout << lastC << endl;
                smileStartTime = 100;
                if(lastC < 8){
                    flag = 3;
                }else if(lastC < 16){
                    flag = 4;
                }else if(lastC < 24){
                    flag = 5;
                }else if(lastC < 32){
                    flag = 6;
                }else {
                    flag = 7;
                }
            }
        }
    }
    
    if(flag == 30){
        movLevel1.update();
    }else if(flag == 40){
        movLevel2.update();
    }else if(flag == 50){
        movLevel3.update();
    }else if(flag == 60){
        movLevel4.update();
    }else if(flag == 70){
        movLevel5.update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255,255,255);
    stringstream ss;
    ss << "framerate: " << ofToString(ofGetFrameRate(), 0);
    ofDrawBitmapString(ss.str(), 1150, 20);
    
    
      if(loopflag==0){
    if(flag == 0){
        ofSetColor(255,255,255);
        start.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
    }
    }
    if(loopflag == 1){
       if(flag == 1){
        
        if(countFlagStart == 0){
            count3.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
        }else if(countFlagStart == 1){
            count2.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
        }else if(countFlagStart == 2){
            count1.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
        }else if(countFlagStart == 3){
            smileStartTime = ofGetSeconds();
            flag = 2;
        }
    }
    
        if(flag == 2){
        cam.draw(0, 0);
        smile.draw();
        if(!findSmileFlg){
            
        }
        if(countFlag == 0){
            font.drawString("5", 60, 100);
        }else if(countFlag == 1){
            font.drawString("4", 60, 100);
        }else if(countFlag == 2){
            font.drawString("3", 60, 100);
        }else if(countFlag == 3){
            font.drawString("2", 60, 100);
        }else if(countFlag == 4){
            font.drawString("1", 60, 100);
            loopflag =2;
        }else if(countFlag == 5){
            smileStartTime = ofGetSeconds();
        }
        
    }
       
    }
    if(countFlag == 5){
        b_push.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
        if(flag == 3){
            ofSetColor(100, 149, 237);
            font.drawString("SMILE LEVEL 1 (MAX:5)", 275, 310);
        }else if(flag == 4){
            ofSetColor(107, 142, 35);
            font.drawString("SMILE LEVEL 2 (MAX:5)", 275, 310);
        }else if(flag == 5){
            ofSetColor(255, 215, 0);
            font.drawString("SMILE LEVEL 3 (MAX:5)", 275, 310);
        }else if(flag == 6){
            ofSetColor(255, 140, 0);
            font.drawString("SMILE LEVEL 4 (MAX:5)", 275, 310);
        }else if(flag == 7){
            ofSetColor(255, 69, 0);
            font.drawString("SMILE LEVEL 5 (MAX:5)", 275, 310);
        }
}
    
    

    
    bool res = true;
  
    if(flag == 30){
        movLevel1.draw(0, 0,1280,800);
        res = movLevel1.isPlaying();
        if(res == false){
            flag = 10;
        }
    }else if(flag == 40){        movLevel2.draw(0, 0,1280,800);
        res = movLevel2.isPlaying();
        if(res == false){
            flag = 10;
        }
    }else if(flag == 50){        movLevel3.draw(0, 0,1280,800);
        res = movLevel3.isPlaying();
        if(res == false){
            flag = 10;
        }
    }else if(flag == 60){
        movLevel4.draw(0, 0,1280,800);
        res = movLevel4.isPlaying();
        if(res == false){
            flag = 10;
        }
    }else if(flag == 70){        movLevel5.draw(0, 0, 1280,800);
        res = movLevel5.isPlaying();
        if(res == false){
            flag = 10;
        }
    }
    if(flag == 10){
            thank.draw((1280 - 729*1.5)/2, 30, 729*1.5, 516*1.5);
    }

    }


//--------------------------------------------------------------
    void ofApp::keyPressed(int key){
        if (key == 'a'){
            
            
            
            if(flag == 0){
                startTime = ofGetSeconds();
                flag = 1;
                loopflag = 1;
            }
        }
        else if(key == 'b'){
            if(flag == 3){
                movLevel1.play();
                flag = 30;
               
            }else if(flag == 4){
                movLevel2.play();
                flag = 40;
            
            }else if(flag == 5){
                movLevel3.play();
                flag = 50;
              
            }else if(flag == 6){
                movLevel4.play();
                flag = 60;
            
            }else if(flag == 7){
                movLevel5.play();
                flag = 70;
              
            }
        }
        
        if (key == 'q') {
            c=0;
            countFlag = 0;
            countFlagStart = 0;
            flag = 0;
            loopflag = 0;
            movLevel1.stop();
            movLevel1.firstFrame();
            movLevel2.stop();
            movLevel2.firstFrame();
            movLevel3.stop();
            movLevel3.firstFrame();
            movLevel4.stop();
            movLevel4.firstFrame();
            movLevel5.stop();
            movLevel5.firstFrame();
            
            
        }

    
}

