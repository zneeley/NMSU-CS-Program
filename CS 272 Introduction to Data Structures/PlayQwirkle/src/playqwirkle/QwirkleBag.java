/**
 * QwirkleBag - models the bag used for playing the game Qwirkle
 * @author Esther Steiner
 * @since September 14, 2018
 */

package playqwirkle;

public class QwirkleBag extends Object implements Cloneable
{

   // instance variables

   private QwirkleTile[ ] tiles;
   private int numTiles; 
   private int bagCapacity;   

   // constructor

   public QwirkleBag( )
   {
      bagCapacity = 108;
      numTiles = 108;

      tiles = new QwirkleTile[bagCapacity];
      for (int i = 0; i < bagCapacity; i++)
         tiles[i] = new QwirkleTile( i % 6 + 1, i % 36 / 6 + 1 );
   }
  
   public String toString() {
      
      String answer = "";
      for (int i = 0; i < numTiles; i++)
        answer = answer + tiles[i].toString() + "\n";
      return answer;
   }

   public void add(QwirkleTile element) 
   {
      if (numTiles == tiles.length)
      { 
         System.out.println("The bag is full.  Cannot add a tile.");
         return;
      }

      tiles[numTiles] = element;
      numTiles++;
   }


   public int countOccurrences(QwirkleTile target) {
      int count = 0;
  
      for (int index = 0; index < numTiles; index++)
         if (target.equals(tiles[index]))
            count++;

      return count;
   }

   public boolean remove(QwirkleTile target)
   {
      // use a linear search algorithm to find the first
      // occurrence of target (if it exists in the bag)
      int i;
      for (i = 0; (i < numTiles) && (!target.equals(tiles[i])); i++);
         
      if (i == numTiles)  // target was not found
         return false;

      numTiles--;
      tiles[i] = tiles[numTiles];
      return true;
   }
   
   public QwirkleTile draw( ) {
   
      if (numTiles == 0)
         return null;
      
      int pick = (int) (Math.random() * numTiles);
      QwirkleTile chosen = tiles[pick];
      tiles[pick] = tiles[numTiles-1];
      numTiles--;
   
      return chosen;
   }// end draw
      
} // end class
