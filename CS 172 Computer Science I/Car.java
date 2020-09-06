// Program name: Car
// Lab number: 7
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/31/17
// This class will work with strings to make a basic class to return information to CarTest
// Input: This class will take int and strings from the CarTest program.
// Output: This class will return a toString method.

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
    } // End Car
    
    // accessors
    // Return make if called
    public String getMake () {
        return make;
    } // End getMake
    
    // Return model if called
    public String getModel () {
        return model;
    } // End getModel
    
    // Return year if called
    public int getYear () {
        return year;
    } // End getYear
    
    // mutators 
    // Set make to str
    public void setMake (String str) {
        make = str;
    } // End setMake
    
    // Set model to str
    public void setModel (String str) {
        model = str;
    } // End setModel
    
    // Set year to str
    public void setYear (int x) {
        if (x >= 0) {
            year = x;
        }
    } // End setYear
    
    // toString
    public String toString() {
       // Formate for the ans string
        String ans = year + " " + make + " " + model + "\n";
        return ans;
    } // End toString
    
    
} // End Class
