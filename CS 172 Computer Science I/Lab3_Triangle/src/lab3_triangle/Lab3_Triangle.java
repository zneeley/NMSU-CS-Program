/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3_triangle;

import java.util.Scanner;

public class Lab3_Triangle {

    public static void main(String[] args) {
        double a, b, c;
        Scanner scan = new Scanner(System.in);
        
        // Prompt user and store to a
        System.out.println("Enter the value of a: ");
        a = scan.nextDouble();
        
        // Prompt user and store b
        System.out.println("Enter the value of b: ");
        b = scan.nextDouble();
        
        // Math calc lenth of Hypotenuse and print
        c = Math.sqrt(a * a + b * b);
        System.out.println("The length of the hypotenuse is: " + c);
    }
    
}
