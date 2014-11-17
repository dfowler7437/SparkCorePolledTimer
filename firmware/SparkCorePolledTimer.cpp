//Check header file for detials on use...
//#include "application.h"
#include "SparkCorePolledTimer.h"

SparkCorePolledTimer::SparkCorePolledTimer(unsigned long timeoutMS){
    Reset();
    SetTimeout(timeoutMS);
    callback=NULL;
}

void SparkCorePolledTimer::SetTimeout(unsigned long timeoutMS){
    intervalMS=timeoutMS;
}

void SparkCorePolledTimer::Reset(void){
    timeMark=millis();
}

int SparkCorePolledTimer::HasElapsed(){
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

void SparkCorePolledTimer::Update(void){
    if (callback!=NULL) {
        if(HasElapsed()) {
            callback();
        }
    }
}

void SparkCorePolledTimer::SetCallback(void (*callbackFunction)(void)){
    callback=callbackFunction;
}

