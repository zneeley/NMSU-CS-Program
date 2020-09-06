// Program name: ClockTest
// Lab number: 7
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/31/17
// This program will practice working with class named clock to create a clock and
// Clocktest will test out each part of the class to see if it is working correctly
// Input: This program will need int from the user to pass to the class
// Output: Will pass the clock from the clock class and print it console and if the isEqualTo method
// is true or false

import java.util.*;

public class ClockTest {

    public static void main(String[] args) {
        // init
        Scanner scan = new Scanner(System.in);
        Clock time = new Clock();
        int timer[] = new int[3];
        int compair = 0;
        int tickTimes = 1;
        boolean equal;
        
        // Test getSecond, getMinute, getHour also assign it to timer index 0-2
        timer[0] = time.getSecond();
        System.out.println("Default second is: " + time.getSecond());
        timer[1] = time.getMinute();
        System.out.println("Default minute is: " + time.getMinute());
        timer[2] = time.getHour();
        System.out.println("Default hour is: " + time.getHour());
        
        
        // Ask for how many times to tick
        System.out.println("Enter the amount of times you want to clock to tick: ");
        tickTimes = scan.nextInt();
        
        // Look untill i is less then tickTimes
        for (int i = 0; i < tickTimes; i++) {
        // Pass information to tick method and get the returned values
        timer = Clock.tick(timer[2], timer[1], timer[0]);
        
        // Assign the returned values to the setHour, setMinute, and setSeconds in the class.
        time.setHour(timer[2]);
        time.setMinute(timer[1]);
        time.setSecond(timer[0]);
        } // For loop
        
        // Print the outcome from the tick class
        System.out.println("The clock is " + time.toString());
        
        // Ask for a number to search for
        System.out.println("Please enter a number would would like to compair: ");
        compair = scan.nextInt();
        
        // Pass the current clock to the class then and see if returned true or false
        equal = Clock.isEqualTo(compair, timer[0], timer[1], timer[2]);
        
        // If true then say so or false then say so
        if (equal == true) {
           System.out.println("The number " + compair + " matches the clocks hour, minute, second." + time.toString());
        } else {
           System.out.println("The number " + compair + " does not match the clocks hour, minute, second.");
        } // If and else statement
        
    } // End Main
    
} // End Class