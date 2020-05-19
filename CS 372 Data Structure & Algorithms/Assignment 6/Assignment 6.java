package bst.temp;
/*
/* Zachary Neeley
/* 4/23/2020
/* CS 372
/*
/* BST Code Gotten from https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ 
/* The code has been modified to fit the needs of the assignments. Most of the modified code is located in the public static void main(String[] args)  
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BSTTemp { 

    public static int[] treePrint = new int[100];
    public static int treeNodes = 0;
    
    /* Class containing left and right child of current node and key value*/
    class Node { 
        int key; 
        Node left, right; 
  
        public Node(int item) { 
            key = item; 
            left = right = null; 
        } 
    } 
  
    // Root of BST 
    Node root; 
  
    // Constructor 
    BSTTemp() {  
        root = null;  
    } 
  
    // This method mainly calls insertRec() 
    void insert(int key) { 
       root = insertRec(root, key); 
    } 
      
    /* A recursive function to insert a new key in BST */
    Node insertRec(Node root, int key) { 
  
        /* If the tree is empty, return a new node */
        if (root == null) { 
            root = new Node(key); 
            return root; 
        } 
  
        /* Otherwise, recur down the tree */
        if (key < root.key) 
            root.left = insertRec(root.left, key); 
        else if (key > root.key) 
            root.right = insertRec(root.right, key); 
  
        /* return the (unchanged) node pointer */
        return root; 
    } 
  
    // This method mainly calls InorderRec() 
    void inorder()  { 
       inorderRec(root); 
    } 
  
    // A utility function to do inorder traversal of BST 
    void inorderRec(Node root) { 
        if (root != null) { 
            inorderRec(root.left); 
            //System.out.println(root.key); 
            treePrint[treeNodes] = root.key;
            treeNodes++;

            inorderRec(root.right); 
        } 
    } 
  
    // Driver Program to test above functions 
    public static void main(String[] args) { 
        BSTTemp tree = new BSTTemp(); 
        String[] nodesArray = null;
        String[] tempArray = null;
        String[] nodeColors = null;
        int sortedArray[] = new int[100];
        Scanner scan = new Scanner(System.in);
        
        // Get filename
        System.out.println("Enter the file name including the extension. Example: test.txt");
        String filename = scan.nextLine();
        
        // Read file
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);  
            String data = myReader.nextLine();
            nodesArray = data.split(" ");
            myReader.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred. While Reading File.");
            e.printStackTrace();
        }
        
        // Mark Sure the root is a black 
        if (!nodesArray[0].contains("b")) {
            System.out.println("Root is not a black node.");
            System.exit(0);
        }   
        
        // Insert nodes into the tree
        for (int i = 0; i < nodesArray.length; i++){
            String temp = nodesArray[i];
            temp = temp.replace("(", "");
            temp = temp.replace(")", "");
            tempArray = temp.split(",");
            //System.out.println(tempArray[1]);
            int num = Integer.parseInt(tempArray[1]);
            tree.insert(num);
            
        }
        
        
        // Check to see if its a BST
        tree.inorder();
        
        for (int i = 0; i < treePrint.length; i++){
            sortedArray[i] = treePrint[i];
        }
        
        for (int i = 0; i < sortedArray.length; i++){
            
            if (sortedArray[i] != treePrint[i]) {
                System.out.println(sortedArray.toString());
                System.out.println(treePrint.toString());
                System.exit(0);
            }
        }
        
    } 
} 
