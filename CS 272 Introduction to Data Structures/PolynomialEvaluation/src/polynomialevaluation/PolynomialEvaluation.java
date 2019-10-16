/**
 * PolynomialEvaluation - This program will use the methods to calculate out polynomials to the n degree
 * @author Zachary Neeley
 * @since 10/11/2018
 */
package polynomialevaluation;

public class PolynomialEvaluation {

    /**
     * polyOne - will create the polynomial giving the output which will be used later to calculate the big O of this algorithm
     * @param a[] array that contains the random numbers to be used in the polynomial
     * @param x   the degree used to calculate the polynomial
     * @param n   size of the array
     * @return answer return the value of the polynomial as a double
     */
   public static double polyOne( int a[], double x, int n ) {
   
        // init store the incoming array[0] into answer
        double answer = a[0];
        
        // Loop through the array reseting the power on every iteration
        for (int j = 1; j <= n; j++) {
            
            //init setting the power
            double xPower = 1;
            
            // Loop though the array calculating the power
            for (int k = 1; k <= j; k++) {
                xPower = xPower * x;
                
            } // end for k
            
            // Calculate the polynomial by taking answer + array[j] * the power
            answer = answer  + a[j] * xPower;
            
        } // end for j
        
        return answer;
    } // end polyOne
   /**
     * polyTwo - will create the polynomial giving the output which will be used later to calculate the big O of this algorithm
     * @param a[] array that contains the random numbers to be used in the polynomial
     * @param x   the degree used to calculate the polynomial
     * @param n   size of the array
     * @return answer return the value of the polynomial as a double
     */ 
   public static double polyTwo( int a[], double x, int n ) {
   
       //init 
        double answer = 0;
        double xPower = 1;

        // Loop though the array
        for (int j = 0; j <= n; j++) {
            // Calculate the polynomial by taking answer + array[j] * the power
            answer = answer + a[j] * xPower;
            
            // Calc the power for the next iteration
            xPower = xPower * x;
        } // end for j
        
      return answer;  
    } // end polyTwo
   
   /**
     * polyThree - will create the polynomial giving the output which will be used later to calculate the big O of this algorithm
     * @param a[] array that contains the random numbers to be used in the polynomial
     * @param x   the degree used to calculate the polynomial
     * @param n   size of the array
     * @return answer return the value of the polynomial as a double
     */ 
   public static double polyThree( int a[], double x, int n ) {
   
        // Horner's method
        
        // init
        double answer = a[n];
        
        // Loop from the end of the array to 0
        for (int l = (n - 1); l >= 0; l--) {
            
            // Calc the polynomial by taking answer * 1 + a[1];
            answer = answer * l + a[l];
            
        } // end for l
        
        return answer;
    } // end polyThree
    
   /**
    * main - This main program will test the methods polyOne, polyTwo, polyThree and printing their times to the console
    * @param args 
    */
   public static void main (String args[]) {
       
       // Init creates the needed size array the the places to store time
       int size[] = { 10000, 100000, 500000, 1000000};
       long startTime, endTime, tempTime;
      
       //
       // polyOne - Calls the polyOne method, prints the time used to the console
       //

       // Create the table header
      System.out.println("Array Size     polyOne #1(ns)     polyOne #2(ns)");
      System.out.println("------------------------------------------------");
      
      // Loop through the size array 
      for (int i = 0; i < size.length; i++) {
      
          // Create a new array with the size of each number in size array
          int array[] = new int [size[i]];
          
          // Fill the new array with random numbers
          for (int j = 1; j < array.length; j++) {
              array[j] = (int) (Math.random() * (100 + 1));
              
          } // end for j
          
          // Take the current system time
          startTime = System.nanoTime();
          
          // Call polyOne 
          double p1 = polyOne( array, 2.0, array.length - 1 );
          
          // Take the current system time
          endTime = System.nanoTime();
          
          // See how long it took to calc the polynomial store the time into tempTime
          tempTime = endTime - startTime;
          
          // Take current system time
          startTime = System.nanoTime();
          
          // Call polyOne 
          double p2 = polyOne( array, 2.0, array.length - 1 );
          
          // Take the current system time
          endTime = System.nanoTime();
      
        // Print the size of array and how long it took to complete each runs
        System.out.printf("%-15d %-20d %-20d\n",size[i] ,tempTime ,(endTime - startTime));

      }// end for i
      
      // Print 2 new lines
      System.out.println("\n");
      
      //
      // polyTwo
      //
      
      // Create the table header
      System.out.println("Array Size     polyTwo #1(ns)     polyTwo #2(ns)");
      System.out.println("------------------------------------------------");
      
      // Loop through the size array 
      for (int x = 0; x < size.length; x++) {
      
          // Create a new array with the size of each number in size array
          int array[] = new int [size[x]];
          
          // Fill the new array with random numbers
          for (int y = 1; y < array.length; y++) {
              array[y] = (int) (Math.random() * (100 + 1));
          } // end for y
          
          // Take the current system time
          startTime = System.nanoTime();
      
          // Call polyTwo
          double p1 = polyTwo( array, 2.0, array.length - 1 );
      
          // Take the current system time
          endTime = System.nanoTime();
          
          // See how long it took to calc the polynomial store the time into tempTime
          tempTime = endTime - startTime;
          
          // Take the current system time
          startTime = System.nanoTime();
      
          // Call polyTwo
          double p2 = polyTwo( array, 2.0, array.length - 1 );
      
          // Take the current system time
          endTime = System.nanoTime();
      
      // Print the size of array and how long it took to complete each runs 
        System.out.printf("%-15d %-20d %-20d\n",size[x] ,tempTime ,(endTime - startTime));

      }// end for x
      
      System.out.println("\n");
      
      //
      // polyThree
      //
      
      // Create the table header
      System.out.println("Array Size     polyThree #1(ns)     polyThree #2(ns)");
      System.out.println("----------------------------------------------------");
      
      // Loop through the size array 
      for (int w = 0; w < size.length; w++) {
      
          // Create a new array with the size of each number in size array
          int array[] = new int [size[w]];
          
          // Fill the new array with random numbers
          for (int e = 1; e < array.length; e++) {
              array[e] = (int) (Math.random() * (100 + 1));
          } // end for w
          

          // Take the current system time
          startTime = System.nanoTime();
      
          // call polyThree
          double p1 = polyThree( array, 2.0, array.length - 1 );
      
          // Take the current system time
          endTime = System.nanoTime();
          
          // See how long it took to calc the polynomial store the time into tempTime
          tempTime = endTime - startTime;
          
          // Take the current system time
          startTime = System.nanoTime();
      
          // Call polyThree
          double p2 = polyThree( array, 2.0, array.length - 1 );
      
          // Take the current system time
          endTime = System.nanoTime();
          
      // Print the size of array and how long it took to complete each runs
        System.out.printf("%-15d %-20d %-20d\n",size[w] ,tempTime ,(endTime - startTime));

      }// end for w
 
   } // end main
   
} // end class