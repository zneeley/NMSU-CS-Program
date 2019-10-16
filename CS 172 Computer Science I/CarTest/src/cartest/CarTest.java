/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cartest;

import java.util.*;

public class CarTest {

    public static void main(String[] args) {
        Car car = new Car();   
        Scanner scan = new Scanner(System.in);
        String make;
        String model;
        int year;
        
        System.out.println("Please input the Manufacture of the car: ");
        make = scan.nextLine();
        car.setMake(make);
        
        System.out.println("Please input the model of car: ");
        model = scan.nextLine();
        car.setModel(model);
        
        System.out.println("Please input the year of the car: ");
        year = scan.nextInt();
        car.setYear(year);
        
        System.out.println("The car you added is: " + car.toString());
        
        
    }
    
}
