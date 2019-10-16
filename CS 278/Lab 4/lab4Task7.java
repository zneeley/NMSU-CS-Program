/*
Name: Zachary Neeley
Date: 2/20/2019
Assigment: Lab 4 Task 7
Task: Write a Java program to verify that the formula you obtained in Task 6 is correct for n = 1, 2, . . . , 10000.
*/

package lab4task7;

public class Lab4Task7 {

    public static void main(String[] args) {
        
        // Check to see if the values match if so print the answer.
        for (long i = 0; i <=10000; i++) {
            if (sim1toN_NewFormula(i) == iSquardedValues(i)){
                System.out.println(i + "    The values are the same.");
            } else {
                System.out.println("THE NUMBERS DO NOT MATCH   " + i);
            } // end else
        } // end for
    }
    
    // Get the values of all the i^2 below it.
    public static long iSquardedValues(long n) {
        long answer = 0;
        for (long i = 0; i <= n; i++) {
            answer = answer + (i * i);
        } // end for 
        
        return answer;
    } // end iSquaredValues
    
    public static long sim1toN_NewFormula(long n) {
        return ((n * (n+1) * ((2 * n) +1)) /6);
        
    } // end sim1toN_NewFormula
    
}
