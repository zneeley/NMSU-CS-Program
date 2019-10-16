#include <IRremote.h> // Library for remote sensing
#include <avr/interrupt.h> // Library for interrupts

// ------------------------------------------- Lab 8
int receiver = 10; // PB2 or Digital pin 10 used for remote sensing
IRrecv irrecv(receiver);  // create instance of 'irrecv'
decode_results results;   // create instance of 'decode_results'


extern byte remotecommand[]; // The array we would be sharing with AVR
unsigned char * onechar; // Used for int to byte conversion
int remotevalue; // Used for int to byte conversion
extern byte command; // Used to return the command for the respective remote signal

// ------------------------------------------ Lab 9

long start_time;
long totduration;
long end_time;        // Used for the storage of end_time
extern byte pinbstate;

// ----------------------------------------- Lab 10

byte savecommand;

// -----------------------------------------------------------------------

extern "C" {
  // ------ Lab 7
  void initAD();
  int readAD(int);
  
  // ------ Lab 8
  void control();
  void controlMotor();

  // ------- Lab 9 
  void ultrasensor();
  void readPINBState();

  // ------- Lab 10
  void UltraMotorOff();
  void UltraMotorCounter();
  void UltraMotorClock();
  void UltraLEDOn();
  void UltraLEDOff();
}

void setup() {
  Serial.begin(9600);   //Begin serial communication

  // ----------------- Lab 7
  initAD();

  // ----------------- Lab 8
  irrecv.enableIRIn();  //enable the IR pin connected to PB2 or digital pin 10

  // ----------------- Lab 9  
  PCMSK0 = (1<<PCINT1);

  // Enable the corresponding vector, PCIE0 in our case.
  PCICR = (1<<PCIE0);

  // Enable the interrupt flag
  sei(); 

  // -----------------------------
}


void loop() {
  // -----------------------------------------------------------------
  //                              Lab 9
  // -----------------------------------------------------------------
  ultrasensor();
  
  // -----------------------------------------------------------------
  //                              Lab 8
  // -----------------------------------------------------------------
  savecommand = command;
  if(irrecv.decode(&results)){    //have we received an IR signal?
    remotevalue = results.value;
     
    for(size_t i=0; i<2; i++){    //We only need the last 2 bytes.
      onechar = (unsigned char *)(&remotevalue); // convert the base address of integer 'remotevalue' to an unsigned char address
      onechar = onechar + i;    //Add the offset to get the respective byte
      remotecommand[i] = *onechar; //Store the byte into 'remotecommand'
    }
    delay(1000);              //To avoid signal interference
    irrecv.resume();          //receive the next value
  }

  // FIX, use Serial.print() to figure out what the upper and lower bytes of the Remote you pressed here

    delay(1000);
    controlMotor();               //FIX --incomment this when you get your controller working
    delay(1000);
}

// -----------------------------------------------------------------
//                              Lab 9
// -----------------------------------------------------------------
ISR(PCINT0_vect)
{
  /* The echo pin is changed twice
   * 1. First echo pin is set, this is when the echo is sent,
   * record start time in microseconds
   * 2. Then echo pin is cleared, this is when the echo came
   * back, record the end time now.
   */

   // Read the pin b state to know if its 0 or 1
   readPINBState();

   if(pinbstate == 1)   // If pinbstate is 1 store value into start_time
    start_time = micros();

   if(pinbstate == 0)   // If pinbstate is 0 store value into end_time and calc
   {
    end_time = micros();
    totduration = (end_time - start_time);    // See the difference in time store to totduration
    Serial.println(totduration);              // Print totduration to the serial

    if (totduration >= 1200) {      
      Serial.println("Safe Distance");
      if (savecommand == '<') {
        UltraMotorCounter();
        UltraLEDOff();
      } else if (savecommand == '>') {
        UltraMotorClock();
        UltraLEDOff();
      } else if (savecommand == '!') {
        UltraLEDOff();
      } else if (savecommand == '^') {
          UltraLEDOn();
      } else if (savecommand == 'v') {
          UltraLEDOff();    
      } else {
        byte L;
        byte R;
        L = readAD(1);
        R = readAD(2);
        if ( R - L <= 10 && R - L >= -10 ) {
          UltraLEDOff();
          UltraMotorOff();     
        } else if ( R - L > 10 ) {
          UltraLEDOff();
          UltraMotorClock(); 
        } else {
          UltraLEDOff();
          UltraMotorCounter();
        }
      }
    }
    
    
    if (totduration > 800 && totduration < 1200) {
      Serial.println("Getting Close");
      UltraLEDOn();
    } 
    
    if (totduration <= 800) {
      Serial.println("To Close");
      UltraLEDOn();
      UltraMotorOff();
    }
    
     // figure out total time,
     // determine a safe distance (like 5 inches)
     // print out "Save Distance"  or "Too close" based on your science
   }
} 
// --------------------------------------------------------------------
