/**
 * This file use the Polygon interface file. Used to create area and perimeter methods. Used for CS 272 
 * @author Zachary Neeley
 * @since 8/30/2018
 */
package lab2;

public class Triangle implements Polygon{
    
    // Protected varaibles used to store triangle sides
    protected double side1;
    protected double side2;
    protected double side3;
    
    /**
     * Constructor 
     * @param triangleSide1
     * @param triangleSide2
     * @param triangleSide3 
     */
    public Triangle(double triangleSide1, double triangleSide2, double triangleSide3) {
        
        // Check to see if the sides given are a triangle if not print a message to the user
        if (triangleSide1 + triangleSide2 > triangleSide3 && triangleSide1 + triangleSide3 > triangleSide2 && triangleSide2 + triangleSide3 > triangleSide1) {
            // Set the sides given by the constructor
            side1 = triangleSide1;
            side2 = triangleSide2;
            side3 = triangleSide3;
        } else {
            // If the sides are not a real triangle tell the user that program will use default size of 1 then set the sides to 1
            System.out.println("The Sides:" + triangleSide1 + " " + triangleSide2 + " " + triangleSide3 + " is not a valid triangle.");
            System.out.println("Using default size 1 for all sides \n");
            side1 = 1;
            side2 = 1;
            side3 = 1;
        }
    }
    
    /**
     * Method area
     * @return triangleArea
     */
    public double area () {
        
        // Init
        double triangleArea;
        double x;
        
        // Add side 1 2 3 together then divide by 2, store into x
        x = (side1 + side2 + side3) / 2;
                
        // Calc triangleArea using Herons formula
        triangleArea = Math.sqrt(x * (x - side1) * (x - side2) * (x - side3));
        
        // Return area of triangle
        return triangleArea;
        
    } // End Area
    
    /**
     * Method perimeter
     * @return trianglePerimeter
     */
    public double perimeter () {
        // Init
        double trianglePerimeter;
        
        // Add all 2 sides together
        trianglePerimeter = side1 + side2 + side3;
        
        // Return perimeter of triangle
        return trianglePerimeter;
        
    } // End perimeter
    
    /**
     * Method
     * @return triangleInfo
     */
    public String toString() {
        
        //Init
        String triangleInfo;
        
        // Create a string of the object
        triangleInfo = "Triangle: \n" + "Side1: " + side1;
        triangleInfo = triangleInfo + "\nSide2: " + side2;
        triangleInfo = triangleInfo + "\nSide3: " + side3;
        
        // Return triangleInfo 
        return triangleInfo;
        
    } // End toString
} // End Triangle
