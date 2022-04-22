hw_timer_t * timer = NULL; 
volatile bool interruptbool1 = false;

/*Interrupt routine for Timer overflow event*/
void IRAM_ATTR onTimer() {
   interruptbool1 = true; //Indicates that the interrupt has been entered since the last time its value was changed to false 
}


void setup() {
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);                //Begin timer with 1 MHz frequency (80MHz/80)
  timerAttachInterrupt(timer, &onTimer, true);   //Attach the interrupt to Timer1
  unsigned int timerFactor = 1000000;  // 1 sec cntr (1Mhz/1000000)
  timerAlarmWrite(timer, timerFactor, true);      //Initialize the timer
  timerAlarmEnable(timer); 

}

void loop() {
  // put your main code here, to run repeatedly:
  if(interruptbool1){
      Serial.println(millis()/1000);
      interruptbool1 = false;
    }

}
