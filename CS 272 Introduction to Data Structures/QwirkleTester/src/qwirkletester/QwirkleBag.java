/**
 * This file builds off of the QwirkleTile class to create a bag of 108 tiles
 * which can do used for the add, countOccurrences, and draw methods
 * @since 9/13/2018
 */
package qwirkletester;


public class QwirkleBag {
    
    // Init the needed variables
    // Will store the amount in the bag
    private int bagCapacity;
    
    // Stores the number of tiles
    private int numTiles;
    
    // Create an array of QwirkleTile objects
    private QwirkleTile tiles[];
    
    /**
     * Constructor
     */
    public QwirkleBag () {
        // Set the default size of the bags and tiles
        bagCapacity = 108;
        numTiles = 108;
        
        // Create a new index tile
        tiles = new QwirkleTile[bagCapacity];
        
        // Set the tilesIndex to 0
        int tilesIndex = 0;
        
        // Create 3 sets of tiles 
        for (int tileSet = 0; tileSet < 3; tileSet++ ) {
            // Select the color for the current iterration 
            for (int tileColor = 1; tileColor <= 6; tileColor++) {
                // Select the shape for the current color
                for (int tileShape = 1; tileShape <= 6; tileShape++) {
                    
                    // Assine the color and shape to the tiles[] array
                    tiles[tilesIndex] = new QwirkleTile(tileColor, tileShape);
                    // Change the index to the next value
                    tilesIndex++;
                } // End shape loop
            } // End color loop
        } // End set loop
    } // End Constructor
    
    /**
     * Method toString
     * @return String
     */
    public String toString(){
        
        // Empty string to store final output
        String layout = "";
        
        // Look through the tiles[] array  
        for (int i = 0; i < numTiles; i++) {
            
            // Create the string calling the toString from the QwirkleTile to create the string
            // Ex: red clover
            //     blue diamond
            layout = layout + tiles[i] + "\n";
        } // End for loop
        
        return layout;
    } // End toString
    
    /**
     * Method add
     * @param newTile object
     */
    public void add(QwirkleTile newTile) {
        
        // Check to see if the bag is full is so tell user
        if (numTiles == 108) {
            System.out.println("Qwirkle Bag is already filled.");
        } else {
            // If the pag is not full incrument numTiles
            numTiles++;
            
            // Create a new tile in the current index
            tiles[numTiles - 1] = newTile;
        } // End else
    } // End add
    
    
    /**
     * Method countOccurrences
     * @param checkTile
     * @return int
     */
    public int countOccurrences(QwirkleTile checkTile){
        
        // Init count
        int count = 0;
        
        // Loop through the array checking tosee any tiles in the array match the
        // passed tile if so add 1 to count
        for (int i = 0; i < numTiles; i++) {
            if (checkTile.equals(tiles[i])){
                count ++;
            } // End if
        } // End for loop
        
        
        return count;
    } // End countOccurrences
    
    /**
     * Method draw
     * @return QwirkleTile object
     */
    public QwirkleTile draw() {
        // Create a new random number for the index
        int randomIndex = (int)(Math.random() * numTiles - 0 +1) + 0;
        
        // Create a temp object
        QwirkleTile temp;
        
        // Check to see if the bag is empty if so return null
        if (numTiles == 0) {
            return null;
            
        } else {
            
            // Swap the current element to the end of the array moving the 
            // one there to the old index of the random number
            temp = tiles[numTiles -1 ];
            tiles[numTiles -1] = tiles[randomIndex];
            tiles[randomIndex] = tiles[numTiles -1];
            
            // Dec. numTiles to make it so that the last index is not printed
            numTiles--;
            
        } // End else
        
        return tiles[numTiles];
    } // End Draw
} // End QwirkleBag
