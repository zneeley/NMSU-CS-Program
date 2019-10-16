/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab9;

import java.util.Scanner;

/**
 *
 * @author zsxc3
 */
public class Lab9 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int pow;
        int num = 10;
        
        Scanner scan = new Scanner(System.in);
        System.out.println("Please input the exponent for the power of 10: ");
        pow = scan.nextInt();
        
        System.out.print(powerOfTen(num, pow));
    }
    
    public static double powerOfTen(int b, int a) {
        if (a == 0) {
            return 1.0;
        }
        if (a < 0) {
            // Negative power.
            return 1 / powerOfTen(10, - a);
        } else {
            // Positive power
            double powHalf = powerOfTen(10, a / 2);
            double[] factor = { 1, 10 };
            return factor[a % 2] * powHalf * powHalf;
        }
    }
}
