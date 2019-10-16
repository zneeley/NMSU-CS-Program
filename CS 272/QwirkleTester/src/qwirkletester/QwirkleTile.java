/**
 * This file is used to build the class which QwirkleBag uses as its main functions. 
 * This works with only one tile at a time create the color and shapes needed.
 * @author Zachary Neeley
 * @since 9/13/2018
 */
package qwirkletester;

public class QwirkleTile implements Cloneable {
    
    private int color;
    private int shape;
    /**
     * Constructor 
     * @param c stores the color of the tile
     * @param s stored the shape of the tile
     */
    public QwirkleTile (int c, int s) {
        color = c;
        shape = s;
        
    }
    
    /**
     * Accessor getColor 
     * @return none 
     */
    public int getColor() {
        return color;
        
    }
    
    /**
     * Accessor getShape
     * @return none
     */
    public int getShape() {
        return shape;
        
    }
    
    /**
     * Mutator setColor
     * @param c stores the color
     */
    public void setColor(int c) {
        color = c;
        
    }
    
    /**
     * Mutator setShape
     * @param s stores the shape
     */
    public void setShape(int s) {
        shape = s;
        
    }
    
    /**
     * Method equals
     * @param o Object 
     * @return boolean
     */
    public boolean equals (Object o) {
        
        // Create a new object called obj
        QwirkleTile obj = (QwirkleTile) o;
        
        // Check to see if the color and shape match the input
        // return true if they do match, false if they dont
        if (color == obj.color && shape == obj.shape) {
            return true;
        } else {
            return false;
        } // End else
        
    } // end Equals
    
    /**
     * Method clone
     * @return QwirkleTile object
     */
    public QwirkleTile clone() {
        
        // Create a new clone of a tile
        QwirkleTile duplicate = new QwirkleTile(color, shape);
        
        return duplicate;
    } // End clone
    
    /**
     * Method toString
     * @return string
     */
    public String toString() {
        String colorNames[] = {"","Orange", "Green", "Yellow", "Red", "Blue", "Purple"};
        String shapeNames[] = {"","Four-Pointed Star", "Clover", "Eight-Pointed Star", "Diamond", "Square", "Circle"};

        String tile = colorNames[color] + " " + shapeNames[shape];
        return tile;
    } // End toString
    
} // End QwirkleTile
