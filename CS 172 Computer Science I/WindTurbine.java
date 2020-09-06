// Program name: WindTurbine
// Lab number: 8
// CS 172 – section M01
// written by Zachary Neeley
// date written 11/6/17
// This program will work with the TestLab8 program to get information check if it is valid 
// and return the information
// Input: This class will only get information from the TestLab8 program
// Output: This class will return data back to the TestLab8 program

public class WindTurbine {
   // init 
   private double powerOutput = 1.0;
   private int bladeSpeed = 0;
   private String orientation = "Horizontal";
   
   // Constructor 1 
   public WindTurbine() {
      powerOutput = 100;
      bladeSpeed = 300;
      orientation = "Horizontal";
   } // End constructor 1
   
   // Constructor 2
   public WindTurbine(double pow, int speed, String ori) {
      setPowerOutput(pow);
      setBladeSpeed(speed);
      setOrientation(ori);
   } // End constructor 2
   
   // Accessor PowerOutput
   public double getPowerOutput() {
      return powerOutput;
   } // End accessor
   
   // Accessor BladeSpeed
   public int getBladeSpeed() {
      return bladeSpeed;
   } // End accessor
   
   // Accessor Orientation
   public String getOrientation() {
      return orientation;
   } // End accessor
   
   // Mutator PowerOutput will check to see if valid then assign to powerOutput
   public void setPowerOutput(double x) {
      if (x >= 1.0 && x <= 10000.0) {
         powerOutput = x;
      } else {
         powerOutput = 100;
      }
   } // End mutator
   
   // Mutator BladeSpeed will check to see if valid then assign to bladeSpeed
   public void setBladeSpeed(int x) {
      if (x >= 0 && x <= 300) {
         bladeSpeed = x;
      } else {
         bladeSpeed = 0;
      }
   } // End mutator
   
   // Mutator Orientation will check to see if valid then assign to orientation
   public void setOrientation(String x) {
      String ori = x.toLowerCase();
      
      if (ori.contains("horizontal") || ori.contains("vertical")) {
         orientation = x;
      } else {
         orientation = "Horizontal";
      } // End if
   } // End mutator
   
   // toString method will turn all the data from the class
   public String toString() {
      String ans = "WindTurbine: powerOutput: " + getPowerOutput() + "kW bladeSpeed: " + getBladeSpeed()
              + " Orientation: " + getOrientation();
      return ans;
   } // End toString
   
} // End class
