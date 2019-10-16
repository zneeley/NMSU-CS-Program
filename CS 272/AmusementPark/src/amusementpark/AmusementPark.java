/**
 * This program will use use Ride.java and Person.Java to simulate a amusement park.
 * @author Zachary Neeley
 * @since 11/8/2018
 */
package amusementpark;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class AmusementPark {

    /**
     * Main method will be used to simulate an amusement park
     * @param args
     * @throws FileNotFoundException 
     */
    public static void main(String[] args) throws FileNotFoundException {
        
        // Create the rides in the park with their name, time in minutes and number of people 
        Ride RollerCoaster = new Ride("RollerCoaster", 4, 10);
        Ride FerrisWheel = new Ride("Ferris Wheel", 12, 16);
        Ride SuperSlide = new Ride("Super Slide", 8, 6);
        Ride TeaCups = new Ride("Tea Cups", 6, 8);
        
        // CReate the lines for each ride using ArrayQueues 
        ArrayQueue<Person> RLine = new ArrayQueue<Person>(200);
        ArrayQueue<Person> FLine = new ArrayQueue<Person>(200);
        ArrayQueue<Person> SLine = new ArrayQueue<Person>(200);
        ArrayQueue<Person> TLine = new ArrayQueue<Person>(200);
       
        // Setup to get input from file
        File inputFile = new File("input.txt");
        Scanner fileScan = new Scanner(inputFile);
        
        // init
        int randomPeople;
        int range = 10 - 1 + 1;
        char rideChoice;
        String riderName = "";
        
        // Loop until there in no more input from file and the lines are empty and the rides are not running
        while (fileScan.hasNextLine() || !(RLine.isEmpty() && FLine.isEmpty() && SLine.isEmpty() && TLine.isEmpty()) || !(RollerCoaster.isOver() && FerrisWheel.isOver() && SuperSlide.isOver() && TeaCups.isOver())) {
            randomPeople = (int)(Math.random() * range) + 1;
            
            /*
            * Add riders to lines 
            */
            for (int i = 1; i <= randomPeople && fileScan.hasNext(); i++) {
                
                // Get the riders choice and name
                rideChoice = fileScan.next().charAt(0);
                riderName = fileScan.nextLine();
                
                // Greate a new temp person with their name
                Person tempPerson = new Person(riderName);
                
                // See what ride the person is wanting and add them to the Queue
                if (rideChoice == 'R') {
                    RLine.enqueue(tempPerson);
                    
                } // end if 
                
                if (rideChoice == 'F') {
                    FLine.enqueue(tempPerson);
                    
                } // end if
                
                if (rideChoice == 'S') {
                    SLine.enqueue(tempPerson);
                    
                } // end if
                
                if (rideChoice == 'T') {
                    TLine.enqueue(tempPerson);
                    
                } // end if
            } // end for

            
            /*
            * RollerCoaster Operation
            */
  
            // See if the ride is not over 
            if (!RollerCoaster.isOver()) {
                
                // Run the ride
                RollerCoaster.operate();
                
                // See if the ride is over
                if (RollerCoaster.isOver()) {
                    
                    // Unload the ride
                    RollerCoaster.unload();
                    
                } // end if
                
            // if the line is not empty     
            } else if (!RLine.isEmpty()) {
                
                // Add the remaining people to the ride
                while (!RLine.isEmpty() || !RollerCoaster.isFull()) {
                    RollerCoaster.addRider(RLine.dequeue());
                    
                } // end while 
                
                // Start the ride
                RollerCoaster.start();
            } // else if
            
            /*
            * FerrisWheel Operation
            */
            
            // See if the ride is not over
            if (!FerrisWheel.isOver()) {
                
                // Run the ride
                FerrisWheel.operate();
                
                // See if the ride is over
                if (FerrisWheel.isOver()) {
                    
                    // Unload the ride
                    FerrisWheel.unload();
                } // end if
                
            // See if the line is empty
            } else if (!FLine.isEmpty()) {
                
                // Add the remain ing people to the eride
                while (!FLine.isEmpty() || !FerrisWheel.isFull()) {
                    FerrisWheel.addRider(FLine.dequeue());
                    
                } // end while 
                
                // Start the ride
                FerrisWheel.start();
            } // else if
            
            /*
            * SuperSlide Operation
            */
            // See if the ride is not over
            if (!SuperSlide.isOver()) {
                
                // Operate the ride 
                SuperSlide.operate();
                
                // See if the ride is over
                if (SuperSlide.isOver()) {
                    
                    // If so unload the ride
                    SuperSlide.unload();
                } // end if
            
            // See if the line is empty
            } else if (!SLine.isEmpty()) {
                
                // Add the remaining people to the ride
                while (!SLine.isEmpty() || !SuperSlide.isFull()) {
                    SuperSlide.addRider(SLine.dequeue());
                    
                } // end while 
                
                // Start the ride
                SuperSlide.start();
            } // else if
            
            /*
            * TeaCups Operation
            */
            // See if the ride is not over
            if (!TeaCups.isOver()) {
                
                // Operate the ride
                TeaCups.operate();
                
                // See if the ride is over
                if (TeaCups.isOver()) {
                    
                    // If so unload the ride
                    TeaCups.unload();
                } // end if
                
            // See if the line if empty
            } else if (!TLine.isEmpty()) {
                
                // Add the remaining people to the ride
                while (!TLine.isEmpty() || !TeaCups.isFull()) {
                    TeaCups.addRider(TLine.dequeue());
                    
                } // end while 
                
                // Start the ride
                TeaCups.start();
            } // else if

        } // end while
    } // end main
    
} // end class
