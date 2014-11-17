#include "PolledTimer.h"

PolledTimer::PolledTimer(unsigned long timeoutMS){
    Reset();
    SetTimeout(timeoutMS);
    callback=NULL;
}

void PolledTimer::SetTimeout(unsigned long timeoutMS){
    intervalMS=timeoutMS;
}

void PolledTimer::Reset(void){
    timeMark=millis();
}

int PolledTimer::HasElapsed(){
    unsigned long timeCurrent;
    unsigned long timeElapsed;
    int result=false;
  
    timeCurrent=millis();
    timeElapsed=timeCurrent-timeMark;  


    if(timeElapsed>=intervalMS) {
        Reset();
        result=true;
    }
    return(result);  
}

void PolledTimer::Update(void){
    if (callback!=NULL) {
        if(HasElapsed()) {
            callback();
        }
    }
}

void PolledTimer::SetCallback(void (*callbackFunction)(void)){
    callback=callbackFunction;
}

