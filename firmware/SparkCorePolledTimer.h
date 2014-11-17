#ifndef SparkCorePolledTimer_h
#define SparkCorePolledTimer_h
//  **************************************************************
//  SparkCorePolledTimer.h
//  Simple Timer Library for the Spark Core. Lets you do time based events.
//
//  David Fowler 11/16/2014
//  Version 0.2
//  Converted into a Spark core library
//
//  David Fowler 09/07/2010
//  Version 0.2
//  Converted into an Arudino library and renamed to PolledTimer
//
//  David Fowler 11/18/09
//  Version 0.1
//  Eample Usage
//  SparkCorePolledTimer updateTimer(1000);  //Create a timer object and set it's timeout in milliseconds
//  void OnTimer(void);   //Prototype for timer callback method
//
//  setup(){  //Standard setup function...
//    updateTimer.SetCallback(OnTimer);  //Tell the time about the handler function.
//  }
//  
//  loop(){  //Standard loop function...
//    updateTimer.Update();  //Must call this often in your loop. It will call the
//                           //handler method automatically when it's time too
//  }
//
//  void OnTimer(void) {  //Handler for the timer, will be called automatically
//     //do your time based stuff here...
//  }
//  **************************************************************
#include "application.h"

#define TIMECTL_INIT      0

class SparkCorePolledTimer {
  private:
    unsigned long timeMark;
	unsigned long intervalMS;
	void (*callback)(void);
  public:
    SparkCorePolledTimer(unsigned long timeoutMS);
	void SetTimeout(unsigned long timeoutMS);
	void Reset(void);
	int HasElapsed();
	void Update();
	void SetCallback(void (*callbackFunction)(void));
};

#endif