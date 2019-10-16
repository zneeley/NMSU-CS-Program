/**
 * This file use the Polygon interface file. Used to create area and perimeter methods. Used for CS 272 
 * @author Zachary Neeley
 * @since 8/30/2018
 */
package lab2;

public class EquilateralTriangle extends Triangle{
    
    /**
     * Constructor
     * @param triangleSide 
     */
    public EquilateralTriangle (double triangleSide) {
        
        super(triangleSide, triangleSide, triangleSide);
        
    } // End constructor
    
    /**
     * Method area
     * @return area
     */
    public double area() {
        
        // Calls the Triangle area method
        return super.area();
        
    } // End area
    
    public String toString() {
        
        // Init
        String triangleInfo;
        
        // Creates a string of sides
        triangleInfo = "Equilateral Triangle: \n" + "All Sides: " + side1;
        
        // Return triangleInfo
        return triangleInfo;
    } // End toString
} // End EquilateralTriangle
