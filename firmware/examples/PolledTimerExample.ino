#include "SparkCorePolledTimer/SparkCorePolledTimer.h"

SparkCorePolledTimer updateTimer(1000);  //Create a timer object and set it's timeout in milliseconds
void OnTimer(void);   //Prototype for timer callback method

void setup() {
  Serial1.begin(115200);  
  updateTimer.SetCallback(OnTimer);
}

void loop() {
   updateTimer.Update();
}

void OnTimer(void) {  //Handler for the timer, will be called automatically
  Serial1.println("Hello");
}