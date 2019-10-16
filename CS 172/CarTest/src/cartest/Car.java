/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cartest;

public class Car {
    // init
    private String make;
    private String model;
    private int year;
    
    // constructor
    public Car () {
        make = "";
        model = "";
        year = 0;
    }
    
    // accessors
    public String getMake () {
        return make;
    }
    
    public String model () {
        return model;
    }
    
    public int year () {
        return year;
    }
    
    // mutators 
    public void setMake (String str) {
        make = str;
    }
    
    public void setModel (String str) {
        model = str;
    }
    
    public void setYear (int x) {
        if (x >= 0) {
            year = x;
        }
    }
    
    // toString
    public String toString() {
        String ans = year + " " + make + " " + model + "\n";
        return ans;
    }
    
    
}
