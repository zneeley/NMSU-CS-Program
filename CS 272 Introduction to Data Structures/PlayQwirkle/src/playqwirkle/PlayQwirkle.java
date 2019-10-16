/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package playqwirkle;

public class PlayQwirkle {

    /**
     * Main method
     * @param args
     * @throws CloneNotSupportedException 
     */
    public static void main(String[] args) throws CloneNotSupportedException{
        // Create a QwirkleBag with 108 tiles
        QwirkleBag theBag = new QwirkleBag();
        
        // Create a linked list to store a player's deck
        SinglyLinkedList <QwirkleTile> deck = new SinglyLinkedList();
        
        // Draw 6 tiles from the bag and add them to the deck
        for (int i = 1; i <= 6; i++) {
            deck.addFirst(theBag.draw());
        }
        
        // Print the contents of the deck
        System.out.println("The player's deck contains: \n");
        System.out.println(deck.toString() + "\n");
        
        /*
         * Test #1
         */
        System.out.println("******************* Test 1 *******************");
        // Create one QwirkleTile that is an orange 4-pointed star then create a new list and add the tile to the list
        
        QwirkleTile orangeStar = new QwirkleTile(1,1);
        SinglyLinkedList <QwirkleTile> gridTest1 = new SinglyLinkedList();
        gridTest1.addFirst(orangeStar);
        
        // Create a new SinglyLinkedList variabled called myMove
        SinglyLinkedList <QwirkleTile> myMove;
        
        // Call possible move and store in myMove
        // If myMove is empty, print "There is no possible move."
        // Other wise pring myMove
        myMove = possibleMove(deck, gridTest1);
        
        if (myMove.toString().equals("empty list")) {
            System.out.println("There is no possible move.");
            
        } else {
            System.out.println(myMove.toString());

        }
        
        /*
         * Test #2
        */
        System.out.println("******************* Test 2 *******************");
        // A) Draw one tiles from the bag and print the tile
        QwirkleTile otherTile;
        otherTile = theBag.draw();
        System.out.println("New grid: " + otherTile + "\n");
        
        // B) Make a new SinglyLinkedList object call it gridTest2
        SinglyLinkedList <QwirkleTile> gridTest2 = new SinglyLinkedList();
        
        // C) Add the tile that is drawn in step A to the list
        gridTest2.addFirst(otherTile);
        
        // D) Make a new SinglyLinkedList variable called moveList
        SinglyLinkedList <QwirkleTile> moveList;
        
        // E) Call possibleMove and store it's return in moveList 
        moveList = possibleMove(deck, gridTest2);
        
        // F) If moveList is empty, print "There is no possible move." else print moveList.
        if (moveList.toString().equals("empty list")) {
            System.out.println("There is no possible move.");
            
        } else {
            System.out.println(moveList.toString());

        }
        
        // Traverse moveList one-by-one, remove those tiles from the player's deck
        
        // Create 2 nodes needed to traverse the lists 
        Node <QwirkleTile> walk = moveList.getHead();
        Node <QwirkleTile> walk2 = deck.getHead();
        
        // Loop through the moveList list
        while (walk != null) {
            
            // Loop through the deck list
            while (walk2 != null) {
                
                // If the 2 elements match remove that element
                if (walk.getElement().equals(walk2.getElement())) {
                    deck.remove(walk2.getElement());
                } // end if
                
                // Get next value for walk2
                walk2 = walk2.getNext();
            } // end while walk2
            
            // Get next value for walk
            walk = walk.getNext();
            
        } // end while walk
        
    } // end main
    
    /**
     * Method possibleMove
     * @param d SinglyLinkedList variable that is used for the users deck
     * @param g SinglyLinkedList variable that is used for the games current grid
     * @return movesPossible
     * @throws CloneNotSupportedException 
     */
    public static SinglyLinkedList<QwirkleTile> possibleMove(SinglyLinkedList<QwirkleTile> d, SinglyLinkedList<QwirkleTile> g) throws CloneNotSupportedException{
        
        // Create a new movesPossible list
        SinglyLinkedList<QwirkleTile> movesPossible = new SinglyLinkedList();
        
        // Create 2 nodes to walk though the lists 
        Node <QwirkleTile> walk = d.getHead();
        Node <QwirkleTile> moveWalking = movesPossible.getHead();
        
        // Booleans needed to see if the color or shape is found
        boolean equalsTo = false, choiceColor = false, choiceShape = false;
        
        // Loop through the Deck list
        while (walk != null) {
            
            // If the colors for the grid and deck are the same and not the shapes 
            if (g.first().getColor() == walk.getElement().getColor() && g.first().getShape() != walk.getElement().getShape()) {
                
                // If the color is being used to look at the grid set choiceColor True
                if (!choiceColor && !choiceShape) {
                    choiceColor = true;
                    
                    // If movesPossible is empty add the move to the list
                    if (movesPossible.isEmpty()) {
                        movesPossible.addFirst(walk.getElement());
                    
                    } else {
                        // Loop through the movesPossible list
                        while (moveWalking != null) {
                            
                            // If the grid is equal to the deck set equalsTrue
                            if (moveWalking.getElement().equals(walk.getElement())) {
                                equalsTo = true;
                            
                            } // end if
                            
                            // Get the next value in the list
                            moveWalking.getNext();
                            
                        } // end while moveWalking
                        
                        // If it was not equal to then add the element to the last spot in movesPossible
                        if (!equalsTo) {
                            movesPossible.addLast(walk.getElement());
                        
                        } // end if
                    
                    } // end else
                } // end if choice
            } // end if color
            
            // Reset moveWalking to head and equalsTo to false
            moveWalking = movesPossible.getHead();
            equalsTo = false;
            
            // If the shapes are the same but not the colors
            if (g.first().getColor() != walk.getElement().getColor() && g.first().getShape() == walk.getElement().getShape()) {
                
                // Set it so that it only works with shapes 
                if (!choiceColor && !choiceShape) {
                    choiceShape = true;
                    
                    // If movesPossible isempty add the move to the list
                    if (movesPossible.isEmpty()) {
                        movesPossible.addFirst(walk.getElement());
                    
                    } else {
                        
                        // Loop through the movesPossible list
                        while (moveWalking != null) {
                        
                            // If they are the same tile set equalsTo to true
                            if (moveWalking.getElement().equals(walk.getElement())) {
                                equalsTo = true;
                            
                            } // end if 
                        
                            // Set moveWalking to the next value
                            moveWalking = moveWalking.getNext();
                            
                        } // end while moveWalking
                    
                        // If it does not equal get the last element in the list to that move
                        if (!equalsTo) {
                            movesPossible.addLast(walk.getElement());
                        } // end if  
                    } // end else shapes 
                } // end if choice 
            } // end if shapes
            
            // Set walk to the next value
            walk = walk.getNext();
        } // end While 
        
        // Return the final list of possible moves
        return movesPossible;
        
    } // end possibleMoves 
    
} // end class
