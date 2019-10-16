/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


package lab8;

import java.awt.*;

public class QwirkleTile implements Cloneable {

   // instance variables
   private int color;
   private int shape;
   
   /**
    * Constructs a new Qwirkle tile
    * @param c the color of the tile (values 1 through 6)
    * @param s the shape of the tile (values 1 through 6)
    */
   public QwirkleTile ( int c, int s ) {
   
      // if invalid parameter values, default to 1
        
      if (c >= 1 && c <= 6)
         color = c;
      else
         color = 1;
   
      if (s >= 1 && s <= 6)
         shape = s;
      else 
         shape = 1;
   } // end constructor
   
   /**
    * Accessor for Color
    * @return integer value 1 through 6
    */
   public int getColor( ) {
      return color;

   } // end getColor
   
   /**
    * Accessor for shape
    */
   public int getShape( ) {
      return shape;

   } // end getShape
   
   /**
    * Mutator for color
    * @param c new color value, 1 through 6
    */
   public void setColor( int c ) {
   
      // doesn't change color if c is invalid
      if ( c >= 1 && c <= 6 )
         color = c;

   } // end setColor
   
   /**
    * Mutator for shape
    * @param s new shape value, 1 through 6
    */
   public void setShape( int s ) {
   
      // doesn't change shape if s is invalid
      if ( s >= 1 && s <= 6 )
         shape = s;

   } // end setShape
   
   
   /**
    * Provides a string representation of a QwirkleTile
    * @return String contains the word for the color and the word for the shape
    */
   public String toString( ) {
   
      String colorNames[] = {"", "orange", "green", "yellow",
                             "red", "blue", "purple"};
      String shapeNames[] = {"", "four-pointed star", "clover", "eight-pointed star",
                              "diamond", "square", "circle"};
      if (color < 1 || color > 6 || shape < 1 || shape > 6)
         return "unknown";
      
      return colorNames[color] + " " + shapeNames[shape];
   
   } // end toString
   
   /**
    * Compares two tiles
    * @param o a reference to a QwirkleTile
    * @return true if the tiles have the same color and shape, false otherwise
    */
   public boolean equals (Object o) {
    
      // see pages 138 - 140 in the textbook
      if (o == null) return false;
      
      if (getClass() != o.getClass()) return false;
      
      QwirkleTile other = (QwirkleTile) o;
      
      return (color == other.color && shape == other.shape);
   
   } // end equals
   
   /**
    * Make a clone of a tile
    * @return a QwirkleTile object
    */
   public QwirkleTile clone( ) throws CloneNotSupportedException {

      // see page 144 in the textbook
      
      QwirkleTile other;
      
      other = (QwirkleTile) super.clone();
      other.setColor(color);
      other.setShape(shape);
      return other;

   } // end clone
   
} // end Tile Class