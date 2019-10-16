/**
 * This program will use use BinaryTreeNode and BinarySearchTree to create a Binary Tree and using methods to interact with the tree
 * @author Zachary Neeley
 * @since 11/29/2018
 */

package lab10;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Lab10 {

    /**
     * Will be used to implement the needed methods to test the binary tree 
     * @param args
     * @throws FileNotFoundException 
     */
    public static void main(String[] args) throws FileNotFoundException{
        // init
        String inputVal;
        int inputInt;
        
        // Create a new tree
        BinarySearchTree<Integer> newTree = new BinarySearchTree();
        
        // Create a new scanner and point it to the Lab10input.txt
        File inputFile = new File("Lab10input.txt");
        Scanner fileScan = new Scanner(inputFile);
        
        // See if the file can be read and has data in it.
        if (inputFile.canRead()) {
            // Print showing the file can be read and has data
            System.out.println("The file was opened and has data");
                   
            // Get the next line in the file store it in the inputVal string and parse the int to the inputVal int.
            inputVal = fileScan.nextLine();
            inputInt = Integer.parseInt(inputVal);
        
            // Add add the int to the root of the tree
            newTree.addRoot(inputInt);
        
            // Loop until the file does not have anything else to read
            while (fileScan.hasNextLine()) {
                // Get the next line in the file store it in the inputVal string and parse the int to the inputVal int.
                inputVal = fileScan.nextLine();
                inputInt = Integer.parseInt(inputVal);
                
                // Add the new val to the tree
                newTree.TreeAdd(newTree.root(), inputInt);

            } // end while
        
            // Print out the order of the tree
            newTree.inOrderTraversal(newTree.root());
        
            // See if a value is in the tree
            if (newTree.TreeSearch(newTree.root(), 43).getElement() == 43) {
                System.out.println("The value 43 was found.");
                
            } // end if
            
            if (newTree.TreeSearch(newTree.root(), 962).getElement() != 962) {
                System.out.println("The number 962 was not found.");
                
            } // end if

            if (newTree.TreeSearch(newTree.root(), 4).getElement() == 4) {
                System.out.println("The value 4 was found.");
                
            } // end if
        
        } // end if
        
    } // end main
    
} // end class
