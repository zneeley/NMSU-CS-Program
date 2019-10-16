/**
 * This program will use ArrayStacks to see if a set of qwirkle tile objects fit in a row
 * @author Zachary Neeley
 * @since 11/1/2018
 */
package lab8;

public class Lab8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws CloneNotSupportedException{
        // Create a new stack of QwirkleTiles
        ArrayStack<QwirkleTile> myTileStack = new ArrayStack<QwirkleTile>();
        
        // An array of QwirkleTile objects
        QwirkleTile testTiles[] = {new QwirkleTile(1, 1), new QwirkleTile(4, 2), new QwirkleTile(3, 5), new QwirkleTile(4, 6)};
        
        
        // Push all the tiles onto the stack
        for (int i = 0; i < testTiles.length; i++) {
            myTileStack.push(testTiles[i]);
        }
        
        // Print out the stack
        System.out.println("The stack contains: ");
        System.out.println(myTileStack.toString());
        
        // See if the tiles form a valid row
        if (validRow(myTileStack) == true) {
            System.out.println("The tiles for a valid row.");
        }
        
        if (validRow(myTileStack) == false) {
            System.out.println("The tiles do not form a valid row.");
        }
        
        System.out.println();
        
        // Show the stack was not changed
        System.out.println("The stack contains: ");
        System.out.println(myTileStack.toString());
        
    } // end main
    
    /**
     * This method will check to see if the tiles in the tempStack are playable in a valid row.
     * @param tempStack ArrayStack reference
     * @return boolean true or false
     */
    public static boolean validRow(ArrayStack<QwirkleTile> tempStack) throws CloneNotSupportedException{
        
       // Create 2 new stacks
       ArrayStack<QwirkleTile> newStack = new ArrayStack<QwirkleTile>(tempStack.size());
       ArrayStack<QwirkleTile> newStack1 = new ArrayStack<QwirkleTile>(tempStack.size());
       
       // Clone the originial stack
       newStack = tempStack.clone();
       
       // Create a temperary tile
       QwirkleTile tempTile;
       
       
       // Loop untill the stack is empty
       while (!newStack.isEmpty()) {
           
           // Get the tile that we are comaparing to
           tempTile = newStack.pop();
           
           // Clone the newStack onto newStack1
           newStack1 = newStack.clone();
           
           // Loop untill stack is empty
           while (!newStack1.isEmpty()) {
               
              // Get the next tile to compare with
               QwirkleTile tempTile2 = newStack1.top();
               
               // Check to see if the tiles do not form a valid row
               if (tempTile.getColor() != tempTile2.getColor() || tempTile.getShape() != tempTile2.getShape()) {
                   return false;
                   
               } // end if
               
               // Remove the tile from the stack
               newStack1.pop();
               
           } // end Whilte newStack1
       } // end while newStack
       
       return true;
    } // end valid row
    
}// end QwirkleRowTest
