/*
 * Perimeter.java
 * 
 * Print the perimeter of a rectangle with given lengeth and width.
 */
package volume;


public class Volume {

    public static void main(String[] args) {
        // Declare double data type for the needed data
        double height;
        double diameter;
        double volume;
        double radius;
        
        // Declare numbers for the needed data
        height = 5;
        diameter = 8;
        
        // Math to cal. volume
        radius = (diameter / 2);
        volume = (Math.PI * (radius * radius) * height);
        
        // Print out all the needed info
        System.out.println("The volume of the cylinder is:" + volume);
        System.out.println("The height of the cylinder is: " + height);
        System.out.println("The diameter of the cylinder is: " + diameter);
        
        
    } // End Main
    
} // End Class
