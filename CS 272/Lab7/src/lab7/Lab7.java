/**
 * This file draws a snowFlake in a JPanel using recursions to complete the take.
 * @since 10/25/2018
 * @author Zach Neeley
 */
package lab7;

public class Lab7 {

    /**
     * Main function calls binaryPrint and printList  
     * @param args the command line arguments
     */
    public static void main(String[] args)  throws CloneNotSupportedException{
        
        System.out.println("-----Binary Test ------\nThe number -5 in binary is: ");
        binaryPrint(-5);
        
        System.out.println("\n\nThe number 0 in binary is: ");
        binaryPrint(0);
        
        System.out.println("\n\nThe number 10 in binary is: ");
        binaryPrint(10);
        
        System.out.println("\n----- printList Test -----");
        
        // Create a new list.
        SinglyLinkedList<Double> myList = new SinglyLinkedList<Double>();
        
        // Add an element to the list
        double starterVal = 0.0;
        myList.addFirst(starterVal);
        
        // Fill the list with double values
        for (int i = 0; i < 10; i++) {
            starterVal++;
            myList.addLast(starterVal);
            
        } // end for
        
        // Print the list
        printList(myList);
        
    } // end main
    
    /**
     * Method binaryPrint will take and number and convert it into binary
     * @param x Incoming number to convert into binary
     */
    public static void binaryPrint(int x) {
        // Error case
        if (x < 0 ) {
            System.out.print("Number cant be negative.");
        } // end if
        
        // Base case
        if (x == 0) {
            System.out.print("0");
            
        } // end if
        
        // Recursive Steps
        if (x > 0 ) {
            binaryPrint(x / 2);
            System.out.print(x % 2 );
            
        } // end if
    } // end binary Print
    
    public static void printList(SinglyLinkedList<Double> e ) throws CloneNotSupportedException {
        
        SinglyLinkedList<Double> cloneCopy = e.clone();
        
        // Base case
        if (cloneCopy.isEmpty()) {
            return;
        } else {
            System.out.print(cloneCopy.getHead().getElement() + " " );
        }
        
        // Remove the 1st node in the list
        cloneCopy.removeFirst();
        
        // Recursive steps
        printList(cloneCopy);
        return;
    } // end printList
    
} // end class