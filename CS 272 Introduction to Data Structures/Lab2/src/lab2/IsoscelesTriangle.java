/**
 * This file use the Polygon interface file. Used to create area and perimeter methods. Used for CS 272 
 * @author Zachary Neeley
 * @since 8/30/2018
 */
package lab2;

public class IsoscelesTriangle extends Triangle {
    
    /**
     * Constructor
     * @param triangleSide1
     * @param triangleSide2 
     */
    public IsoscelesTriangle (double triangleSide1, double triangleSide2) {
        
        // Call the constructor from the Triangle.java file
        super(triangleSide1, triangleSide1, triangleSide2);
        
    } // End constructor
    
    /**
     * Method area
     * @return area
     */
    public double area() {
        // Init
        double area;
        double height;
        
        // Will create the height for a triangle 
        height = Math.sqrt((Math.pow(side1, 2)) - (Math.pow(side3 / 2 ,2)));
        
        // Calc the area for the triangle
        area = (side3 * height) / 2;
        return area;

    } // End area
    
    /**
     * Method toString
     * @return toString
     */
    public String toString() {
        
        //Init
        String triangleInfo;
        
        // Creates a string that will tell the user the sides
        triangleInfo = "Isoceles Triangle: \n" + "Side1: " + side1 + "\nSide3: " + side2;
        triangleInfo = triangleInfo + "\nSide2: " + side3;
        
        // Return triangleInfo
        return triangleInfo;
        
    } // End toString
} // End IsoscelesTriangle