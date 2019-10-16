/*
 * Zachary Neeley
 * 5/1/19
 * Lab 11 Task 3-7
*/

package Lab11;

import java.util.*;

public class Task3Through6 {


 public static void main(String[] args) {
  System.out.println(generatorNum(5));
  System.out.println(generatorNum(6));
  System.out.println(generatorNum(7));
  System.out.println(generatorNum(8));
 }

 public static double generatorNum(int value) {
  //init
  Random r = new Random();
  int n = value;
  double sum = 0;
  double m = 0;
  double temp = 0;
  
  // Loop for the needed numbers
  for (int i = 1; i <= 100000; i++) {
   int nOfOne = 0;
   int nOfTwo = 0;
   int nOfThree = 0;
   int nOfFour = 0;
   int nOfFive = 0;
   int nOfSix = 0;
   int nOfSeven = 0;
   int nOfEight = 0;
   
   // for loop
   for (int j = 1; j <= n; j++) {

	// Switch for the needed numbers of the random generated number 
    int number = r.nextInt(n) + 1;
    switch (number) {
     case 1:
      nOfOne = nOfOne + 1;
      break;
     case 2:
      nOfTwo = nOfTwo + 1;
      break;
     case 3:
      nOfThree = nOfThree + 1;
      break;
     case 4:
      nOfFour = nOfFour + 1;
      break;
     case 5:
      nOfFive = nOfFive + 1;
      break;
     case 6:
      nOfSix = nOfSix + 1;
      break;
     case 7:
      nOfSeven = nOfSeven + 1;
      break;
     case 8:
      nOfEight = nOfEight + 1;
      break;
     default:
	  System.out.println("Unknown Number");
    }// end switch
	
	
    temp = Math.pow(nOfOne, 2) + Math.pow(nOfTwo, 2) + Math.pow(nOfThree, 2) + Math.pow(nOfFour, 2) 
			+ Math.pow(nOfFive, 2) + Math.pow(nOfSix, 2) + Math.pow(nOfSeven, 2) + Math.pow(nOfEight, 2);
   } // end for
   
   
   sum = sum + temp;
  }// end for
  
  m = sum / 100000;
  return m;

 } // end


}