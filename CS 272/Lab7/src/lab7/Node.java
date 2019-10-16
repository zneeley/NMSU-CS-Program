/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab7;

/**
 *
 * @author zsxc3
 */
/**
 * Node of a singly linked list, which stores a reference to its
 * element and to the subsequent node in the list (or null if this
 * is the last node).
 */
public class Node<E> {

    private E element;            // reference to the element stored at this node
    private Node<E> next;         // reference to the subsequent node in the list

    /**
     * Constructor: Creates a node with the given element and next node.
     *
     * @param e  the element to be stored
     * @param n  reference to a node that should follow the new node
     */
    public Node( E e, Node<E> n ) {
       element = e;
       next = n;
    } // end constructor
     
    /**
     * Accessor for element
     */
    public E getElement( ) { 
       return element;
    } // end accessor
    
    /**
     * Accessor for next
     */
    public Node<E> getNext( ) {
       return next;
    } // end accessor
    
    /**
     * Mutator for element
     */
    public void setElement( E e ) {
       element = e;
    } // end mutator
    
    /**
     * Mutator for element
     * @param reference to a node
     */
    public void setNext( Node<E> n ) {
       next = n;
    } // end mutator
    
   /**
    * Provide a String representation of a node
    * @return a String
    */
   public String toString( ) {
      return element.toString();
   } // end toString method
   
} // end Node class   
        
