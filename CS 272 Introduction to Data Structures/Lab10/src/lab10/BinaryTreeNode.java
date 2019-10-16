/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab10;

// This class represents a node in a binary tree.
// It has been adapted for use in CS 272 from the 
// Node class on pages 326 in the textbook by 
// Goodrich, Tamassia, and Goldwasser

public class BinaryTreeNode<E extends Comparable <E>>
{
   // instance variables
   private E element;
   private BinaryTreeNode<E> parent;
   private BinaryTreeNode<E> left;
   private BinaryTreeNode<E> right;
   
   // constructor
   public BinaryTreeNode (E e, BinaryTreeNode<E> above, BinaryTreeNode<E> leftChild,
                     BinaryTreeNode<E> rightChild) {
      element = e;
      parent = above;
      left = leftChild;
      right = rightChild;
   }
               
   // accessors
   public E getElement( ) {
      return element;
   }
   
   public BinaryTreeNode<E> getParent( ){
      return parent;                                               
   } 
   
   public BinaryTreeNode<E> getLeft( ){
      return left;                                               
   } 
   
   public BinaryTreeNode<E> getRight( ){
      return right;                                               
   } 
   
   // mutators 

   public void setElement(E newElement){
      element = newElement;
   }                                                               
      
   public void setParent(BinaryTreeNode<E> newParent){                    
      parent = newParent;
   }

   public void setLeft(BinaryTreeNode<E> newLeft){                    
      left = newLeft;
   }
    
   public void setRight(BinaryTreeNode<E> newRight) {                    
      right = newRight;
   }  
   
   
   public boolean hasLeft( ) {
   
      if (left != null)
          return true;
          
      return false;
   }
   
   public boolean hasRight( ) {
    
      if (right != null)
         return true;
         
      return false;
   }
   
   public boolean isInternal( ) {
   
      return numChildren( ) > 0;
   }
   
   /** returns true if the node is a leaf (no children) */
  
   public boolean isExternal( ) {
   
      return numChildren( ) == 0;
      
   }
   
   /** returns the number of children this node has */
   public int numChildren( ) {
   
       return (left != null ? 1 : 0) + (right != null ? 1 : 0);
       
   }
   
   
   /** return the sibling, if any, of this node
       if no sibling, return null */
   public BinaryTreeNode<E> sibling( ) {
   
      if (parent == null)
         return null;
         
      if (parent.left == this)
         return parent.right;
         
      return parent.left;
   
   }
   
   /** determine the height of a subtree with this node
       as its root */
   public int height( ) {

      int h = 0;
      
      if (left != null)
         h = Math.max(h, 1 + left.height());
         
      if (right != null)
         h = Math.max(h, 1 + right.height());
      
      return h;
   }
   
   public String toString( ) {
   
      return "BTNode: " + element.toString() + " \nParent: " +
             
             ( parent == null ? "none" : parent.getElement().toString() )
             
              + " \nLeft: " + 
              
              ( left == null ? "none" : left.getElement().toString() )
               
             + " \nRight: " 
             
             + ( right == null ? "none" : right.getElement().toString() );
   }
      
          
} // end class BinaryTreeNode