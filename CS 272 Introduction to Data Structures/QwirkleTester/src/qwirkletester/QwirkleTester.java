/**
 * This file will test the QwirkleTile and QwirkleBag classes which will be used 
 * in Lab 4 to create the Qwirkle game.
 * @author Zachary Neeley
 * @since 9/13/2018
 */
package qwirkletester;

public class QwirkleTester {

    public static void main(String[] args) {
        // Create a new object to use with the QwirkleBag class
        QwirkleBag game1 = new QwirkleBag( );
        
        // Create a newTile object to test the add function.
        // This will call the construtor of the QwirkleTile Class storing the 
        // information in the newTile object.
        QwirkleTile newTile = new QwirkleTile(1, 5);
        
        // Tell the user that a new bag has been created and generate a new bag
        // printing to console the contents.
        System.out.println( "I created a new QwirkleBag. Here's what's in it:\n");
        System.out.println(game1);
        
        // 
        System.out.println("Same Occurrences of a Orange Square: " + game1.countOccurrences(newTile));
        
        // Check to see if a new tile could be added to the bag.
        // Will fail showing the user "Qwirkle Bag is already filled."
        game1.add(newTile);
        
        // Draw a rendom tile out of the bag and show the user what was drawn.
        System.out.println(game1.draw());
        
        // Check to see if a new tile could be added to the bag.
        // Will pass and print out the new contents of the bag.
        game1.add(newTile);
        System.out.println("Printing out current bag with a new tile last." + game1.toString());
    } // End main
    
} // End class
