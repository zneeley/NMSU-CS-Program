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
public class SinglyLinkedList<E> implements Cloneable {
  
  /** The head node of the list */
  private Node<E> head;               

  /** The last node of the list */
  private Node<E> tail;               

  /** Number of nodes in the list */
  private int size;                      

  /** Constructs an initially empty list. */
  public SinglyLinkedList() {
     head = null;
     tail = null;
     size = 0;
  }              


  /**
   * Accessor method for size
   * @return number of elements in the linked list
   */
  public int size() { 
     return size; 
  } // end accessor

  /**
   * Accessor for head
   * @return reference to the first node in the list, or null if the list is empty
   */ 
  public Node<E> getHead( ) {
     return head;
  } // end accessor
  
  /**
   * Accessor for tail
   * @return reference to the last node in the list, or null if the list is empty
   */ 
  public Node<E> getTail( ) {
     return tail;
  } // end accessor
  
  
  /**
   * Tests whether the linked list is empty.
   * @return true if the linked list is empty, false otherwise
   */
  public boolean isEmpty() { 
     return size == 0; 
  } // end isEmpty method

  /**
   * Returns (but does not remove) the first element of the list
   * @return element at the front of the list (or null if empty)
   */
  public E first() {             
    if (isEmpty()) 
       return null;
    return head.getElement();
  } // end first method

  /**
   * Returns (but does not remove) the last element of the list.
   * @return element at the end of the list (or null if empty)
   */
  public E last() {              
    if (isEmpty()) 
       return null;
    return tail.getElement();
  } // end last method


  /**
   * Adds an element to the front of the list.
   * @param e  the new element to add
   */
  public void addFirst(E e) {                
     head = new Node<>(e, head);             
     if (size == 0)
         tail = head;                 // special case: new node becomes tail also
     size++;
  }

  /**
   * Adds an element to the end of the list.
   * @param e  the new element to add
   */
  public void addLast(E e) {                 
    Node<E> newest = new Node<>(e, null);    // create the new node
    if (isEmpty())
      head = newest;                         // special case: previously empty list
    else
      tail.setNext(newest);                  // new node is placed after existing tail
    tail = newest;                           // tail is changed to point to the new node
    size++;
  }

  /**
   * Removes and returns the first element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeFirst() {                   
    if (isEmpty()) 
       return null;                   // if the list is empty, nothing to remove
    E answer = head.getElement();
    head = head.getNext();            // head will become null if list had only one node
    size--;
    if (size == 0)
       tail = null;                   // special case: if list is empty, tail becomes null
    return answer;
  } // end removeFirst method
  
  /**
   * Produces a string representation of the contents of the list.
   * @return a String
   */
  public String toString() {
    StringBuilder sb = new StringBuilder("(");
    Node<E> walk = head;
    while (walk != null) {
      sb.append(walk.getElement());
      if (walk != tail)
        sb.append(", ");
      walk = walk.getNext();
    } // end while loop
    sb.append(")");
    return sb.toString();
  } // end toString method

  @SuppressWarnings({"unchecked"})
  /**
   * Compares two lists to see if the nodes are the same
   * @param o  a SinglyLinkedList object, parent class Object is used by convention
   * @return true if the lists contain the same elements, false otherwise
   */
  public boolean equals(Object o) {
    // safety measure, check for a null value in o
    if (o == null) 
       return false;
    // safety measure, make sure that o is really a SinglyLinkedList reference   
    if (getClass() != o.getClass()) 
       return false;
    
    // now we know that o is a reference to a SinglyLinkedList, we
    // can use a widening conversion to cast it to SinglyLinkedList   
    SinglyLinkedList other = (SinglyLinkedList) o;   
    
    // safety measure, make sure the lists are the same size
    if (size != other.size) 
       return false;
    
    Node walkA = head;                               // traverse the primary list
    Node walkB = other.head;                         // traverse the secondary list
    while (walkA != null) {
      if (!walkA.getElement().equals(walkB.getElement())) return false; //mismatch
      walkA = walkA.getNext();
      walkB = walkB.getNext();
    } // end while loop
    
    return true;   // if we reach this point, everything matched successfully
    
  } // end equals method

  @SuppressWarnings({"unchecked"})
  public SinglyLinkedList<E> clone() throws CloneNotSupportedException {
    
    // always use inherited super.clone() to create the initial copy
    SinglyLinkedList<E> other = (SinglyLinkedList<E>) super.clone(); 
    
    // if there are nodes in the list, we have to copy each one
    if (size > 0) {                    
      // first, make a new Node object for the first node of the new list
      other.head = new Node<>(head.getElement(), null);
      
      Node<E> walk = head.getNext();      
      Node<E> otherTail = other.head;     
                         
      while (walk != null) {              // walk through remainder of original list
                                          // make a new node storing same element
        Node<E> newest = new Node<>(walk.getElement(), null);
        otherTail.setNext(newest);        // link previous node to this one
        otherTail = newest;
        walk = walk.getNext();
      } // end while loop
    } // end if
    
    return other;
  } // end clone method
  
} // end class


