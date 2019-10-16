/**
 * This file will implement the Triangle, IsoscelesTriangle and EquilateralTriangle classes. Used for CS 272 
 * @author Zachary Neeley
 * @since 8/30/2018
 */
package lab2;

import java.util.Scanner;

public class Lab2 {

    public static void main(String[] args) {
        
        // Variables used for the user interface loop
        boolean endLoop = false;    //Used when the user puts -1 into the
        int userChoice;             //Will store the input from the user
        
        Scanner scan = new Scanner(System.in);
        
        // Variables and Setup for the Triangle, IsoscelesTriangle and EquilateralTriangle classes
        double triSide1;
        double triSide2;
        double triSide3;
        
        // Class objects
        Triangle triangle1;
        IsoscelesTriangle isoscelestriangle1;
        EquilateralTriangle equilateraltriangle1;
        
        // This loop will keep the user in the program until userChoice is -1 which will stop the loop
        // The user can input which triangle they are wanting then will be asked for the sides.
        // Finially the program will display the dimentions on the triangle, area and perimeter. 
        while (endLoop != true) {
            System.out.println("Please type the number that corresponds with the triangle needed: \n  1: Equilateral \n  2: Isosceles \n  3: General Triangle \n -1: Exit");
            System.out.print("Choice: ");
            userChoice = scan.nextInt();
        
            System.out.println();
            
            // Equilateral Triangle 
            if (userChoice == 1) {
                System.out.println("Equilateral Triangle: \n");
                
                // Ask for the size of a side and store to triSide1
                System.out.print("Input size a side: ");
                triSide1 = scan.nextDouble();
                System.out.println();
                
                // Pass the input from the user to the constructer for EquilateralTriangle
                equilateraltriangle1 = new EquilateralTriangle(triSide1);
                
                // Show the user information about their triangle including the size of the sides, area and perimeter
                System.out.println("Triangle Information: \n");
                System.out.println(equilateraltriangle1.toString());
                System.out.println("Area: " + equilateraltriangle1.area());
                System.out.println("Perimeter: " + equilateraltriangle1.perimeter());
                System.out.println();
            } // End if
            
            // Isosceles Triangle
            if (userChoice == 2) {
                System.out.println("Isosceles Triangle: \n");
                
                // Ask for sides 1 and 3 because both have the same size and store into triSide1
                System.out.print("Input size of Side 1 (same size as Side 3: ");
                triSide1 = scan.nextDouble();
                System.out.println();
            
                // Ask user for Side 2 and store into triSide2
                System.out.print("Input size of Side 2: ");
                triSide2 = scan.nextDouble();
                System.out.println();
                
                // Pass user input to the IsoscelesTriangle constructor
                isoscelestriangle1 = new IsoscelesTriangle(triSide1, triSide2);
                
                // Show the user information about their triangle including the size of the sides, area and perimeter
                System.out.println("Triangle Information: \n");
                System.out.println(isoscelestriangle1.toString());
                System.out.println("Area: " + isoscelestriangle1.area());
                System.out.println("Perimeter: " + isoscelestriangle1.perimeter());
                System.out.println();
                
            } // End if
        
            // General Triangle
            if (userChoice == 3) {
                System.out.println("General Triangle: \n");
                
                // Ask for side 1 and store into triSide1
                System.out.print("Input size of Side 1: ");
                triSide1 = scan.nextDouble();
                System.out.println();
                
                // Ask for side 2 and store into triSide2
                System.out.print("Input size of Side 2: ");
                triSide2 = scan.nextDouble();
                System.out.println();
            
                // Ask for side 3 and store into triSide3
                System.out.print("Input size of Side 3: ");
                triSide3 = scan.nextDouble();
                System.out.println();
            
                // Pass information to the Triangle constructor 
                triangle1 = new Triangle(triSide1, triSide2, triSide3);
                
                // Show the user information about their triangle including the size of the sides, area and perimeter
                System.out.println("Triangle Information: \n");
                System.out.println(triangle1.toString());
                System.out.println("Area: " + triangle1.area());
                System.out.println("Perimeter: " + triangle1.perimeter());
                System.out.println();
                
            } // End if
        
            // If user chooses to exit the program 
            if (userChoice == -1) {
                // Set endLoop to true and say Ending Program
                endLoop = true;
                System.out.println("Ending Program \n");
            
            } // End if
        } // End While
    } // End Main
} // End Lab2
