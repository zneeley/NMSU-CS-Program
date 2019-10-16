// -----------------------------------------------------------------
//                              Lab 8
// -----------------------------------------------------------------

// Constants for motor
      .set PORTB,0x05     //on port B
      .set DDRB,0x04
      .set PINB, 0x03
      .set MOTDATA,0
      .set MOTLATCH,4
      .set M1ENABLE,3
      .set BOARDLED, 5
      .set SWITCH2, 2
      
      .set PORTD,0x0B     //on port D
      .set DDRD,0x0A
      .set MOTCLOCK,4
      .set M2ENABLE,3
      .set M4ENABLE,6
      .set M3ENABLE,5
      
// Constants for LED
      .set PORTC, 0x08    //on port C
      .set DDRC, 0x07

// -----------------------------------------------------------------
//                              Lab 9
// -----------------------------------------------------------------
// Setting constants for ultrasonic sensor 
    .set trigpin, 4; port c pin 4
    .set echopin, 1; port b pin 1
    .set PINB, 0x03
    .set DDIRB, 0x04
    .set DDIRC, 0x07
    .set PORTC, 0x08

// -----------------------------------------------------------------
//                              Lab 7
// -----------------------------------------------------------------
    .set ADCL, 0x0078
    .set ADCH, 0x0079
    .set ADCSRA, 0x007A
    .set ADCSRB, 0x007B
    .set ADMUX, 0x007C
    .set DIDR0, 0x007E

// Macros to push and pop registers without writing them multiple times
.macro pushall 
    push r17
    push r18
    push r19
    push r20
    push r21
    push r22
    push r23
    push r24
    push r25
    push r26
    push r27
    push r28
    push r29
    push r30
    push r31
.endm

.macro popall
    pop r31
    pop r30
    pop r29
    pop r28
    pop r27
    pop r26
    pop r25
    pop r24
    pop r23
    pop r22
    pop r21
    pop r20
    pop r19
    pop r18
    pop r17
.endm

// Data
    .data
    .comm remotecommand, 2
    .global remotecommand ; For getting the 2 byte remote command sent from the .ino side

    .comm command, 1
    .global command ; To return the respective command for a button press
    
     commandlowbyte: ; All low bytes in order of 'commandcode'
     .byte 0xFD, 0xDD, 0x3D, 0x57, 0x1F 
      
     commandhighbyte:  ;All high bytes in order of 'commandcode'
      .byte 0x02, 0x22, 0xC2, 0xA8, 0xE0    

     commandcode:       //you should set command to one of these values based on the values in remotecommand, '.' for not found
     .byte '>', '<', '!', '^', 'v', '.'

     commandlen: ; maximum number of commands
     .byte 5

     // -------------- Lab 9
     .comm pinbstate, 1
     .global pinbstate // used to store the current state of PINB

// Program
    .text
    // --------------- Lab 8
    .global control
    .global controlMotor
    .extern delay

    // --------------- Lab 9
    .global ultrasensor
    .global readPINBState
    .extern delayMicroseconds

    // --------------- Lab 10
    .global UltraMotorOff
    .global UltraMotorCounter
    .global UltraMotorClock
    .global UltraLEDOn
    .global UltraLEDOff

    // --------------- Lab 7
    .global initAD
    .global readAD

control: 
      pushall
      call setupMotor           //Run the loop 3 times.  You should use turnoffmotor, 
                                //turnonclockwise, and turnoncounterclockwise           
mainLoop:        
      call turnonclockwise      //turn the motor clockwise
      call sendMotorByte        // send byte to motor
      call delayTwo             // 2 second selay
      call delayOne             //delay 1 + 2 = 3 seconds

      call turnoffmotor         //turn off 
      call sendMotorByte        // send byte to the motor
      call delayTwo             //delay for 2 seconds

      call turnoncounterclockwise //turn the motor on couterclockwise
      call sendMotorByte          // send byte to the motor
      call delayTwo             // 2 second delay
      call delayOne             //delay 1 + 2 = 3 seconds

      call turnoffmotor         //turn off all the motors
      call sendMotorByte        // send byte to motor
      call delayOne             // delay 1 second

      call turnonlight          //turn on the LED light
      call delayTwo             // send byte to motor
      call delayOne             //delay for a total of 3 seconds

      call turnofflight       //turn off the LED light
 
      popall
      ret                 

setupMotor: 
     
      ldi r20 ,0b11111001       //set ports B and D to be output
      out DDRB, r20
      out DDRD, r20
      ret                 
      
remoteCommand:    //This routine uses the 2 bytes of remote command to determine which of the 
                  //5 inputs are selected
                  //on completion, the shared global variable "command" will be one of 6 values
                  //'<', '>', '!','^','v','.'
               
      pushall     //push all registers so that 'we' do not overwrite a register used by compiler/linker/loader
      
      ldi r26, lo8(remotecommand) //Read the 2 bytes of remote signal in X
      ldi r27, hi8(remotecommand) //Read the 2 bytes of remote signal in X

      ld r19, X+                  //Read last 2 bytes
      ld r18, X+

      ldi r25, 5                    //to ensure the pointer doesn't go out of range             

      ldi r28, lo8(commandlowbyte)  //save the lo byte of Y
      ldi r29, hi8(commandlowbyte)  //save the hi byte of Y

      ldi r30, lo8(commandcode)     //save the lo byte of Z
      ldi r31, hi8(commandcode)     //save the hi byte of Z

loadreg:
      ld r20, Y+          //load reg Y (low-byte)

      cpi r25, 0
      breq NoValue
      
      ld r21, Z+          //load reg Z (command-code)
      
      cp r20, r19         //compare the remote control with the lowbyte
      brne loadreg

      sts command, r21    //store the value of Z into the global var. of command
      popall             //push all the reg. 
      ret                 // of remoteCommand()

NoValue:
      sts command, r21    //store the value of Z into the global var. of command
      rjmp finish         //push all the reg. 
      
controlMotor:
      pushall
      call setupMotor         //Setup motor
      call remoteCommand      //Pattern match the remote command to get a code.  Sets "command"

      lds r22, command        //Load the code

      // Call corresponding utility based on the command code received.
      cpi r22, '>'            // See if < button was pressed
      breq turnonclockwise

      cpi r22, '<'            // See if > button was pressed
      breq turnoncounterclockwise

      cpi r22, '!'            // See if ! button was pressed
      breq turnoffmotor

      cpi r22, '^'            // See if ^ button was pressed
      breq turnonlight

      cpi r22, 'v'            // See if v button was pressed
      breq turnofflight

finish:
      popall
      ret                    
      
turnoffmotor:
      ldi r24, 0x00            //turn off all the motors
      call sendMotorByte       // send byte to motor
      jmp finish

turnonclockwise:      
      ldi  r24, 0b11011000     //turn the motor clockwise
      call sendMotorByte       // send byte to motor
      jmp finish

turnoncounterclockwise:
      ldi r24, 0b00100111      //flip the binary bits to spin in the opp. direction
      call sendMotorByte       // send byte to motor
      jmp finish

turnonlight:
      sbi DDRC, 0x05           //set the fifth bit on (LED LIGHT)
      sbi PORTC, 0x05 
      jmp finish

turnofflight:
      cbi PORTC, 0x05          //clear the fifth bit forever (LED LIGHT)
      jmp finish
      
delay1:                       //Delays for 1 and 255 milliseconds
      pushall
      ldi   r22, 0x01
      ldi   r23, 0x00
      ldi   r24, 0
      ldi   r25, 0
      call  delay
      popall
      ret //of delay1

delayLong:
      pushall     
      ldi   r22, 0xe8
      ldi   r23, 0x13
      ldi   r24, 0
      ldi   r25, 0
      call  delay 
      popall    
      ret //of delayLong
      
delayTwo:                     //delay for 2 seconds
      pushall
      ldi   r22, 0x00
      ldi   r23, 0x08
      ldi   r24, 0x00
      ldi   r25, 0x00
      call  delay
      popall     
      ret //of delayTwo

 delayOne:                     //delay for 1 seconds
      pushall
      ldi   r22, 0x00
      ldi   r23, 0x04
      ldi   r24, 0x00
      ldi   r25, 0x00
      call  delay
      popall     
      ret //of delayOne     

sendOneBit:                 //1-bit transmission
     cbi PORTD, MOTCLOCK    //clear portd 
     sbi PORTB, MOTDATA     //set portb
     call delay1
     
     sbi PORTD, MOTCLOCK    //set the motclock to high
     call delay1
     
     cbi PORTD, MOTCLOCK    //set the motclock to low
     call delay1  
     
     cbi PORTB, MOTDATA     //clear portb
     ret                    //ret

sendZeroBit:                //0-bit transmission
     cbi PORTD, MOTCLOCK    //clear portd 
     cbi PORTB, MOTDATA     //clear portb
     call delay1
     
     sbi PORTD, MOTCLOCK    //set the motclock to high
     call delay1
     
     cbi PORTD, MOTCLOCK    //set the motclock to low
     call delay1  
     
     cbi PORTB, MOTDATA     //clear portb
     ret                    //ret

// latch now should be enabled (one) in order to release 
// the control pattern to the motor driver chips 
latchData:
      sbi   PORTB,MOTLATCH
      call  delay1
      
      sbi   PORTB, M1ENABLE     //make sure PWM outputs are on
      sbi   PORTD, M2ENABLE
      sbi   PORTD, M3ENABLE
      sbi   PORTD, M4ENABLE
      ret

//latch should be zero in order to send the control 
//pattern to shift register    
latchReset: 
      cbi   PORTB,MOTLATCH
      call  delay1
      ret

sendMotorByte:                 //assumes r24 has the byte we want to send
      push  r15
      push  r16
      mov   r15, r24
      call  latchReset
      ldi   r16, 8
smbloop:
      lsl   r15
      brcs  smbone
      call  sendZeroBit   
      rjmp  smbdone
smbone:
      call  sendOneBit
smbdone:
      dec   r16
      brne  smbloop
      call  latchData
      call  latchReset
      pop   r16
      pop   r15
      ret

// -----------------------------------------------------------------
//                              Lab 9
// -----------------------------------------------------------------
// Setup the ultrasonic sensor to send an echo
ultrasensor:

 // Set trig pin to output and echo pin to input
  SBI DDIRC, trigpin // Port C pin 1
  CBI DDIRB, echopin // Port B pin 4
  
  

 // Trig pin is low for 2 microseconds
  CBI PORTC, trigpin // Port C pin 1
  call delay2

 // Trig pin is high for 10 microseconds
  SBI PORTC, trigpin // Port C pin 1
  call delay10
  

 // Finally set trig pin to low, this will send an echo
  CBI PORTC, trigpin // Port C pin 1
  ret

readPINBState:
 //Routine to look at the echo pin and set "pinbstate" the global variable to 1 or 0 based on the pin
    
    // Read PINB in a register, we want to see if the echo pin has been set
    IN r20, PINB          // Take in port B byte and store to r20
    ANDI r20, 0b00000010  //Change the 1st bit to 1
    

    // If the echo pin has been set, it means that the echo has been sent, store 1 in 'pinbstate'
    CPI r20, 0b00000000  //Compare r20 to 0
    BREQ falselabel      // If equal jump to false
    BRNE truelabel       // If not equal jump to true
    // If the echo pin has been cleared, it means that the echo might have come back, store 0 in 'pinbstate'  
falselabel:
    ldi r21, 0          // Store 0 in r21
    STS pinbstate, r21  // Store 0 into pinbstate
    jmp done
    
truelabel:
    ldi r21, 1          // Store 1 in r21
    STS pinbstate, r21  // Store 1 into pinbstate

done:
    ret


delay10:
    pushall          // Protect all regs
    ldi   r22, 0x0A  // Delay for 10
    ldi   r23, 0x00
    ldi   r24, 0x00
    ldi   r25, 0x00
    call  delay
    popall          // Restore all regs
    ret //of delay10

delay2:
    pushall         // Protect all regs
    ldi   r22, 0x02 // Delay for 2
    ldi   r23, 0x00
    ldi   r24, 0x00
    ldi   r25, 0x00
    call  delay
    popall          // Restore all regs
    ret //of delay2

// -----------------------------------------------------------------
//                              Lab 7
// -----------------------------------------------------------------
initAD:
  
  // In DIDR0, set ADC 0-5 to 1 
  ldi r18, 0b00111111
  sts DIDR0, r18

  // In ADCSRA, intialize ADEN to 1, ADPS 2-0 to 111. Set rest to 0
  ldi r19, 0b10000111
  sts ADCSRA, r19

  ret ;; of initAD()


readAD:

  // In ADMUX, set REFS1 and 0 to 01, ADLAR to 1, and MUX 3-0 to pin 2
  ldi r20, 0b01100000
  add r20, r24
  sts ADMUX, r20

  // In ADCSRA, use the ORI command and the 6th bit to 1 to start conversion
  lds r21, ADCSRA
  ORI   r21, 0b01000000
  sts ADCSRA, r21

       // keep looping until 6th bit in ADCSRA is clear ( = 0 )
loop:  lds r21, ADCSRA
        SBRC r21, 6
        rjmp loop

        //set ADCH to r24 and clear r25 so the value is not contaminated for the C program
        lds r24, ADCH
        clr r25

ret
// -----------------------------------------------------------------
//                              Lab 10
// -----------------------------------------------------------------

UltraMotorOff:
    pushall
    call setupMotor
    ldi r24, 0x00            //turn off all the motors
    call sendMotorByte       // send byte to motor
    popall
    ret

UltraMotorClock:
    pushall
    call setupMotor
    ldi  r24, 0b11011000     //turn the motor clockwise
    call sendMotorByte       // send byte to motor
    popall
    ret

UltraMotorCounter:
    pushall
    call setupMotor
    ldi r24, 0b00100111      //flip the binary bits to spin in the opp. direction
    call sendMotorByte       // send byte to motor
    popall
    ret

UltraLEDOn:
    pushall
    sbi DDRC, 0x05           //set the fifth bit on (LED LIGHT)
    sbi PORTC, 0x05 
    popall
    ret

UltraLEDOff:
    pushall
    cbi DDRC, 0x05           //clear the fifth bit on (LED LIGHT)
    cbi PORTC, 0x05
    popall
    ret
