/*
 * Zachary Neeley
 * 2/12/2020
 * CS 372 hw 1
 */

public class Cs372hw1 {

    public static void main(String[] args) {
        int[] fibs = {20,21,22,23,24,25,26,27,28,29};
        // fib1 which will run 10 times 
        System.out.println("Exponential");
        for (int i =0; i <= 9; i++) {
            long startTime = System.nanoTime();
            fib1(fibs[i]);
            long endTime   = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.println("n: "+ fibs[i] + "  Time: " + totalTime);
        }
        
        // fib2 which will run 10 times 
        System.out.println("\n\nPolynomial");
        for (int i =0; i <= 9; i++) {
            long startTime = System.nanoTime();
            fib2(fibs[i]);
            long endTime   = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.println("n: "+ fibs[i] + "  Time: " + totalTime);
        }
        
        // Question 6 part C
        System.out.println("\n\nQuestion 6 Part C");
        boolean run = true;
        int num = 0; 
        
        while (run) {
            long startTime = System.nanoTime();
            fib1(num);
            long endTime   = System.nanoTime();
            
            long totalTime = endTime - startTime;
            if (totalTime >= 10000000) {
                run = false; 
                System.out.println(num + "    Time: " + totalTime);
            }
            
            num++;
        }
    }
    
    // Exponential Algorithm
    public static int fib1(int n){
        if (n == 0) {
            return 0;
        }
        
        if(n == 1) {
            return 1;
        }
        
        return fib1(n-1) + fib1(n-2); 
    }
    
    // Polynomial Algorithm
    public static int fib2(int n){
        if (n == 0) {
            return 0;
        }
        
        int f[] = new int[n+2];
        
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++){

            f[i] = f[i-1] + f[i - 2];
        }
        return f[n];
    }
}
