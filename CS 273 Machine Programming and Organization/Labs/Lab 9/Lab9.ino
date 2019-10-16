 /* Program name: Lab9
 * Purpose: The purpose of this program is to use the ultrasonic sensor which uses interupts to tell the user a distance.
 * Author's Name: Zachary Neeley 800612251
 * Date: 4/17/2018
 * Description: 
 *    a) The input for the program is to take in the distance given by the ultra sonic sensor.
 *    b) Output uses the serial with the distance from the ultra sonic sensor and a message.
 *    c) I know for a fact that the input will either generate a too close message or safe distance
 * Test Results: To test the code I would get a 5 inch ruler and measure the distance that ultra sonic senor is displaying and compare that
 *               number to others in the lab.
 * Lab Questions: 
 *                1) 756 (5 Inches), 251 (1 Inch), 987 (10 inches), 556 (3 inches), 329 (2 inches)
 *                2) 756 + 756 + 329 = 1,841 ( 5 inches + 5 inches + 2 inches) 
 *                3) The distance of this sensor is 3cm to 400 cm. https://www.arduino.cc/en/Tutorial/Ping
 *                4) The ISR cannot by interupted while it is running, if nother interupt if caused that it will have to wait.
 * My opinions: The main thing I learned was how to use a ISR.
 *              The easy part was to set or clear the needed bits in the S file.
 *              The hardest thing to figure out why my program would not print out to serial.
 */
#include <avr/interrupt.h>
long start_time;
long totduration;
long end_time;        // Used for the storage of end_time
extern byte pinbstate;

extern "C" {
  void ultrasensor();
  void readPINBState();
}

void setup()
{
  Serial.begin(9600);
  
  /*
   * Set the bits of the appropriate PCMSKx register high
   * to enable pin change detection on PB1 (port b pin 1). 
   * PCINT1 in our case.
   */
  PCMSK0 = (1<<PCINT1);

  // Enable the corresponding vector, PCIE0 in our case.
  PCICR = (1<<PCIE0);

  // Enable the interrupt flag
  sei();
  
}

void loop()
{
  ultrasensor();
  delay(1000); // delay a second
}

/*
 * The interrupt service routine that would activate on 
 * a value change of PB1
 */
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

    if (totduration <= 750) {                 // If the totduration is less then or equal to 750
      Serial.println("Too close!!!");          // Print Too close!!! to serial
    } else {
      Serial.println("Safe Distance!!!");         // Else print Safe Distance!!! to serial
    }
    
     // figure out total time,
     // determine a safe distance (like 5 inches)
     // print out "Save Distance"  or "Too close" based on your science
   }
}

