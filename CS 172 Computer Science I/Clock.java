// Program name: Clock
// Lab number: 7
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/31/17
// This class will work with the ClockTest program taking in int and creating them into a clock
// Input: This class will need int from ClockTest 
// Output: This class will return booleans, string and int for the ClockTest program

public class Clock {
    // init
    private int hour;
    private int minute;
    private int second;
    
    // constructor 
    public Clock() {
        setHour(1);
        setMinute(0);
        setSecond(0);
    }
    
    // accessors
    // Return hour if called
    public int getHour() {
        return hour;
    } // End getHour
    
    // Return minute if called
    public int getMinute() {
        return minute;
    } // End getMinute
    
    // Return second if called
    public int getSecond() {
        return second;
    } // End getSecond
    
    // mutators
    // Change hour when called
    public void setHour(int x) {
        // Check to see if valid
        if (x >= 1 && x <= 24) {
            hour = x;
        } // End if
    } // end setHour
    
    // Change Minute when called
    public void setMinute(int x) {
        // Check to see if valid
        if (x >= 0 && x <= 59) {
            minute = x;
        } // End if
    } // End setMinute
    
    // Change second when called
    public void setSecond(int x) {
        // Check to see if valid
        if (x >= 0 && x <= 59) {
            second = x;
        } // End if
    } // End setSecond
    
    // toString
    public String toString () {
        // Format for the string method
        String ans = String.format("%02d:%02d:%02d", hour, minute, second);
        return ans;
    } // End toString
    
    // tick method
    public static int[] tick (int hours, int minutes, int seconds) {
       //init
       Clock time = new Clock();
       int timer[] = new int[3];
       timer[0] = seconds;
       timer[1] = minutes;
       timer[2] = hours;
       
       // Add 1 to seconds
       timer[0] = timer[0] + 1;
       
       // Check to see if the seconds are higher then 60 and change the minute by 1 
       // then reset second
       if (timer[0] == 61) {
          timer[0] = 0;
          timer[1] = timer[1] + 1;
       } // End if timers[0]
       
       // Check to see if the minutes are higher then 60 and change the hour by 1 
       // then reset minute
       if (timer[1] == 61) {
          timer[1] = 0;
          timer[2] = timer[2] + 1;
       } // End if timers[1]
       
       // Check to see if the hours are higher then 24 and then reset hour
       if (timer[2] == 25) {
          timer[2] = 0;
       } // End if timers[2]
       return timer;
       
    } // End tick
    
    // equals method
    public static boolean isEqualTo(int x, int sec, int min, int hr) {
       // init
       Clock time = new Clock();
       int compair = x;
       time.setHour(hr);
       time.setMinute(min);
       time.setSecond(sec);
       
       // Check to see if hour, second and minute are then same 
       if (compair == time.getHour() && compair == time.getMinute() && compair == time.getSecond()) {
          return true;
       } // End if
       
       return false;
       
    } // End isEqualTo
    
} // End Class
