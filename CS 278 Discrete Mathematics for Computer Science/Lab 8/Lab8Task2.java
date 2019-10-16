/*
Name: Zachary Neeley
Date: 3/20
Assignment: Lab 8 Task 2
Task: Rewrite the recursive radixSort into an iterative program. Test your program for correctness. 
Then test the program for performance. Report how fast radix sort takes to sort 100 million random integers. 
Also the Java program.
*/

import java.*;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class RadixSort {

   static int[] a;
   static int   n;
   static char  c;

   static public void printData(int k) {
      System.out.format("\n\n");
      if (k>0) System.out.format("Sort on Digit %d\n", k);
      for (int i=0; i<n; i++) System.out.format("%9d\n",a[i]); 
   }

   static public void radixSort(int[] a, int k) {
       // int
      int count = 1;
      
      // Loop until k is less than count
      while( k >= count) {
          
          // sort the values
          stableSort(a, count);
          
          // See if output is wanted if so than print
          if ( c == 'Y'  || c == 'y') {
              printData(count);
          } // end if
          count++;
       
      } // end while
      /*
      if (k==0) return;
      radixSort(a,k-1);
      stableSort(a,k);
      if (c=='Y') printData(k);
      */
   } // end radixSort

   public static void main(String[] args) throws IOException {
      System.out.print("Enter the number of data to generate/sort: ");
      n = (new Scanner(System.in)).nextInt();
      a = new int[n];

      System.out.print("Do you want to print the data and intermediate results? (Y/N) ");
      c = (char) System.in.read();

      Random r = new Random();
      for (int i=0; i<n; i++) a[i] = r.nextInt(1000000000);

      if (c=='Y') printData(0);

      radixSort(a,9); // sort by all 9 digits

      for (int i=0; i<n-1; i++) // check to see if data is sorted
          if (a[i]>a[i+1]) {
             System.out.println("mistake at " + i);
             return;
      }
   }
   
   static public void stableSort(int[] a, int k) {
        int count[] = new int[10];
        int n = a.length;
        int[] temp = new int[n];
        int e = 1;
        for (int i=0; i<k; i++) e *= 10;
        int f = e/10;
        for (int i=0; i<n; i++) count[a[i]%e/f]++;
        for (int i=1; i<10; i++) count[i]+=count[i-1];
        for (int i=n-1; i>=0; i--) temp[--count[a[i]%e/f]]=a[i];
        for (int i=0; i<n; i++) a[i]=temp[i];
    }

}
