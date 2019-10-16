/**
 * This class will be used on a Binary Tree to find values in the nodes
 * @author Zachary Neeley
 * @since 11/29/2018
 */
package lab10;


public class BinarySearchTree<E extends Comparable<E>> {

   // instance variables
   private BinaryTreeNode<E> root;
   private int size;

   // constructor 
   public BinarySearchTree( BinaryTreeNode<E> newRoot ) {

      root = newRoot;
      size = 1;
   }

   public BinarySearchTree( ) {  

      root = null;
      size = 0;

   }

   public int size( ) {

      return size;
   }

   /** returns true if the tree has no nodes, otherwise returns false
   */
   public boolean isEmpty( ) {
   
      return size == 0;
   }
   
   public BinaryTreeNode<E> root( ) {

      return root;
   }

   public boolean isRoot( BinaryTreeNode<E> n ) {
   
      return root == n;
   }
   
      /** returns the number of levels separating a given node
       from the root of the tree */
       
   public int depth( BinaryTreeNode<E> aNode) {
      // base case  
      if (isRoot( aNode ))
         return 0;
      
      // recursive step
      return 1 + depth( aNode.getParent( ) );
   }        

   /** add a node at the root of an empty tree
   */
   public BinaryTreeNode<E> addRoot( E element ) {
   
      if (!isEmpty( )) throw new IllegalStateException( "Tree is not empty");
      root = new BinaryTreeNode<E> (element, null, null, null);
      size = 1;
      return root;
   }
   
   /** add a node as the left child of a specific node
   */
   public BinaryTreeNode<E> addLeft( BinaryTreeNode<E> parentNode, E element ) throws IllegalArgumentException {
   
      if (parentNode == null)
         return null;
      
      if (parentNode.getLeft() != null)
         throw new IllegalArgumentException("node already has a left child");
         
      BinaryTreeNode<E> child = new BinaryTreeNode<E>( element, parentNode, null, null );
      parentNode.setLeft(child);
      size++;
      return child;
   }
 
   /** add a node as the right child of a specific node
   */
   public BinaryTreeNode<E> addRight( BinaryTreeNode<E> parentNode, E element ) throws IllegalArgumentException {
   
      if (parentNode == null)
         return null;
         
      System.out.println("Adding " + element.toString() 
        + " as a right child to node " + parentNode.getElement().toString());
      
      if (parentNode.hasRight())
         throw new IllegalArgumentException("Cannot add " + element.toString() + "\nnode already has a right child");
         
      BinaryTreeNode<E> child = new BinaryTreeNode<E>( element, parentNode, null, null );
      parentNode.setRight(child);
      size++;
      return child;
   }
   
   /** removes the node from the tree and replaces it with
       its child, if any */
   public E remove( BinaryTreeNode<E> node ) throws IllegalArgumentException {
      if (node == null)
         throw new IllegalArgumentException("cannot remove - parameter is null");
      if (node.numChildren() == 2) 
         throw new IllegalArgumentException("cannot remove - node has two children");
         
      BinaryTreeNode<E> child = (node.getLeft() != null ? node.getLeft() 
                                                        : node.getRight());

      if (child != null)
         child.setParent(node.getParent());
      if (node == root)
         root = child;
      else {
         BinaryTreeNode<E> parent = node.getParent();
         if (node == parent.getLeft())
            parent.setLeft(child);
         else
            parent.setRight(child);
      }
      // decrease the size of the tree
      size--;
      
      // help with garbage collection
      E temp = node.getElement();
      node.setElement(null);
      node.setLeft(null);
      node.setRight(null);
      node.setParent(null);
      // the return value is the element from
      // the node that was removed
      return temp;
   } // end remove method
                                         
   public void preOrderTraversal ( BinaryTreeNode<E> start ) {
   
       // visit the node
       System.out.print( start.getElement().toString() + "  " );
       // recursion on left subtree
       if (start.hasLeft()) 
          preOrderTraversal( start.getLeft() );
          
       // recursion on right subtree
       if (start.hasRight())
          preOrderTraversal( start.getRight() );
          
   }
   
   /**
    * This method will search the tree using a starting node and a value to look for.
    * @param startNode
    * @param value
    * @return BinaryTreeNode
    * @throws IllegalArgumentException 
    */
   public BinaryTreeNode<E> TreeSearch( BinaryTreeNode<E> startNode, E value) throws IllegalArgumentException {
       // See if startNode is null and throw an exception
       if (startNode.getElement() == null) {
           throw new IllegalStateException("Node equals null");

       } // end if
       
       // See if startNode equals value
       if (startNode.getElement().equals(value)) {
           return startNode;
           
       } // end if
       
       // See if the node is a leaf
       if (startNode.isExternal()) {
           return startNode;
           
       } // end if
       
       // See if the value is less than the element in the node
       if (value.compareTo(startNode.getElement()) == -1) {
           
           // If the node does not has a left 
           if (!startNode.hasLeft()) {
               return startNode;
               
           } else {
               // Recursive call
               return TreeSearch(startNode.getLeft(), value);
           } // end if else
           
       } else {
           
           // If the tree has a right
           if (!startNode.hasRight()) {
               return startNode;
           } // end if
           
           // Recursive call
           return TreeSearch(startNode.getRight(), value);
           
       } // end if else 
   } // end TreeSearch
   
   /**
    * TreeAdd method will add a node to the tree in the needed position
    * @param startNode
    * @param value
    * @throws IllegalArgumentException 
    */
   public void TreeAdd( BinaryTreeNode<E> startNode, E value) throws IllegalArgumentException {
       
       // Create 2 nodes to use 
       BinaryTreeNode<E> p = TreeSearch(startNode, value);
       BinaryTreeNode<E> PChild = new BinaryTreeNode(value, p, null, null);
       
       // If p equals the value passed print out a message and return
       if (p.equals(value)) {
           System.out.println("The value " + value + " is already in the tree.");
           return;
           
       } // end if
       
       // If value is less then the element in p set p's left to PChild and return
       if (value.compareTo(p.getElement()) == -1) {
           p.setLeft(PChild);
           return;
           
       } // end if 
       
       // Set the right to PChild
       p.setRight(PChild);
       
   } // end TreeAdd
   
   /**
    * inOrderTraversal method will go through the tree printing out the values in the tree using a postorder traversal
    * @param startNode 
    */
   public void inOrderTraversal(BinaryTreeNode<E> startNode) {
       // See if the node has a left then recursive call to go down the left side of the tree
       if (startNode.hasLeft()) {
           inOrderTraversal(startNode.getLeft());
           
       } // end if
       
       // Pring the element in the current node
       System.out.println(startNode.getElement());
       
       // See if the node has a right then recursive call to go down the right side of the tree
       if (startNode.hasRight()) {
           inOrderTraversal(startNode.getRight());
           
       } // end if
   } // end inOrderTraversal
} // end class BinaryTree
