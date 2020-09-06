/*
 * Lab1.java
 * CS 172 - section m01
 * written by Zachary Neeley
 * date written 8/28/17
 * This program calculates the volume of a cylinder
 * Input: height and diameter
 * Output: volume
 */

import java.util.Scanner;


public class Lab1 {

    public static void main(String[] args) {
        // Declare double data type for the needed data
        double height;
        double diameter;
        double volume;
        double radius;
        
        // Init a new scanner
        Scanner scan = new Scanner(System.in);
        
        // Promt user for the height
        System.out.println("Please input the height:");
        
        // Assign the scanner data to height
        height = scan.nextDouble(); 
        
        // Promt user for the diameter
        System.out.println("Please input the diameter:");
        
        // Assign the scanner data to diameter
        diameter = scan.nextDouble();
        
        // Math to cal. volume
        radius = (diameter / 2);
        volume = (Math.PI * (radius * radius) * height);
        
        // Print out all the needed info
        System.out.println("The volume of the cylinder is:" + volume);
        
        
    } // End Main
    
} // End Class
