SparkCorePolledTimer
====================
Simple Timer Library for the Spark Core. Lets you do time based events.

Eample Usage

PolledTimer updateTimer(1000);  //Create a timer object and set it's timeout in milliseconds
void OnTimer(void);   //Prototype for timer callback method

setup(){  //Standard setup function...
    updateTimer.SetCallback(OnTimer);  //Tell the time about the handler function.
}
  
loop(){  //Standard loop function...
    updateTimer.Update();  //Must call this often in your loop. It will call the
                           //handler method automatically when it's time too
}

void OnTimer(void) {  //Handler for the timer, will be called automatically
     //do your time based stuff here...
}
