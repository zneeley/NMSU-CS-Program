/*
Name: Zachary Neeley
Date: 2/20/2019
Assigment: Lab 4 Task 2
Task: Write a Java program to verify that sum1toN recursive returns the same answers as that computed by n*(n+1)/2 for n = 0, 1, 2, . . . 10000.
*/

package lab4.task2;

public class Lab4Task2 {

    public static void main(String[] args) {
        
        // Check to see if the values match if so print the answer.
        for (int i = 0; i <=10000; i++) {
            if (sim1toN_NewFormula(i) == sum1toN_recursive(i)){
                System.out.println(i + "    The values are the same.");
            } else {
                System.out.println("THE NUMBERS DO NOT MATCH   " + i);
            } // end else
        } // end for
    } // end main
    
    // Check N recurrsively 
    public static int sum1toN_recursive( int n ) {
        if (n==0) return 0;
        return n + sum1toN_recursive(n-1);
    } // end sum1toN_recursive
    
    public static int sim1toN_NewFormula(int n) {
        return ((n*(n+1))/2);
    } // end sim1toN_NewFormula
    
    
}
