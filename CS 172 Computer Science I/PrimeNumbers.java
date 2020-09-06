/*CS 172
* Prime Numbers
* Lab 4
* Written by: Zachary Neeley
* 10/3/17
* The purpose of this program is to print prime number at 2 and less then 1000
* INPUT: Nothing from the user.
* OUTPUT: Will print out a right-justified table show all prime numbers from 2 to 1000
*/

public class PrimeNumbers {

    public static void main(String[] args){
       int num = 0; // Init num
       int newLine =169; // Max number of lines
       String primeNumbers = "      "; //Starts the 

       // Calc the prime numbers
       for (int i = 1; i <= 1000; i++){ 		  	  
          int count = 0; // init count 	  
          for(num = i; num >= 1; num --){
             if(i % num == 0) {
 		count = count + 1;
	     }
	  }
          // If the number is prime then add it to the string primeNumbers
	  if (count == 2){
              if (newLine % 10 == 0) {
                  primeNumbers = primeNumbers + i + "\n      "; // Add the new prime number to the string
                  newLine--; // Subtract 1 from numLine
              }
	    primeNumbers = primeNumbers + i + "      ";
            newLine --;
	  }	
       }	
       // Tell the user that the prime numbers are and print the prime numbers
       System.out.println("Prime numbers from 2 to 100 are :");
       System.out.printf("%6s",primeNumbers);
    }
    
}
