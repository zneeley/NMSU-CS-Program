/*
 * Zachary Neeley
 * 5/1/19
 * Lab 11 Task 2
*/

import java.util.Random;

public class Lab11Task2 {
    
        public static void main(String[] args) {
		
		System.out.println("X1 should be 3");
                System.out.println("X2 should be 4/3(1.33)");
                System.out.println("X should be 13/3(4.333)");
		task2();
		
	}//end main
        
    	public static void task2() {
		
		//init arrays
		double[] x1 = new double[100000];
		double[] x2 = new double[100000];
                double count = 0.0;
		Random r = new Random();
		
		//X1 coin experiment
		//init 
		int a = 0;
		int k = 0;
		double sumOfX1 = 0.0;
		double avgOfX1 = 0.0;
                boolean loopCondition = true;
                // Loop until true 
		while (loopCondition){
			//Result with 0 = head, 1 and 2 = tail
			double result = r.nextInt(3);
			count++;
                        
                        // Insert number of throws into the array
			if(result == 0.0 && k < x1.length) {
				x1[k] = count;
				count = 0.0;
				k++;
			//Stop the loop once the array has been filled up
			if (k == x1.length) loopCondition = false;
			}		
		}
		//Get the average of X1
		while (a < x1.length) {
			sumOfX1 += x1[a]; a++;
		} // end while
                
		avgOfX1 = sumOfX1 / 100000;
		System.out.println("X1: " + avgOfX1);
		
		//X2 init
		int b = 0;
		int i = 0;
		double sumOfX2 = 0.0;
		double avgOfX2 =0.0;
                boolean loopCondition2 = true;
		while (loopCondition2){
			//Result with 0 = head, 1 and 2 = tail
			double coinResult = r.nextInt(4);
			count++;
			
                        // Insert number of throws into the array
			if(coinResult == 0 || coinResult == 1 || coinResult == 2 && i < x2.length) {
				x2[i] = count;
				count = 0.0;
				i++;
                                
			//Stop the loop once the array has been filled up
			if (i == x2.length) loopCondition2 = false;
			}		
		}
		//Get the average of X1
		while (b < x2.length) {
			sumOfX2 += x2[b]; b++;
		} // end while
                
		avgOfX2 = sumOfX2 / 100000.0;
		System.out.println("X2: " + avgOfX2);
		
		//x = x1 + x2
		double sumOfX = 0.0;
		sumOfX = avgOfX1 + avgOfX2;		
		System.out.println("X: " + sumOfX);
		
	}// end task2
    
}
