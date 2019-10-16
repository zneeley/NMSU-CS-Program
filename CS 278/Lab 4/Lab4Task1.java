/*
Name: Zachary Neeley
Date: 2/20/2019
Assigment: Lab 4 Task 1
Task: Write a Java program to verify that sum1toN and sum1toN recursive return the same answers for n = 0, 1, 2, . . . 10000.
*/


public class Lab4Task1 {

    public static void main(String[] args) {
        
        // Check to see if the values match if so print the answer.
        for (int i = 0; i <=10000; i++) {
            if (sum1toN(i) == sum1toN_recursive(i)){
                System.out.println(i + "    The values are the same.");
            } else {
                System.out.println("THE NUMBERS DO NOT MATCH   " + i);
            } // end else
        } // end for
    } // end main
    
    // Get the sum of the values to n
    public static int sum1toN( int n ) {
        int sum = 0;
        
        for (int i=1; i<=n; i++)
            sum = sum + i;
            return sum;
    } // end sum1toN
    
    public static int sum1toN_recursive( int n ) {
        n = n + 1;
        if (n==0) return 0;
        return n + sum1toN_recursive(n-1);
    } // end sum1toN_recursive
    
}
