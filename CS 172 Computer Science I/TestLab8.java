// Program name: TestLab8
// Lab number: 8
// CS 172 – section M01
// written by Zachary Neeley
// date written 11/6/17
// This program will work with WindTurbine class trying to pass data that should be invalid
// and see if it will pass.
// Input: None from an outside source, all data is hard coded
// Output: This program will output information from the class to the console

public class TestLab8 {

   public static void main(String[] args) {
      // init
      WindTurbine wtOne = new WindTurbine(); 
      WindTurbine wtTwo = new WindTurbine(800, 90, "Vertical");
      
      // Set the powerOutput, bladeSpeed and Orientation
      wtOne.setPowerOutput(200);
      wtOne.setBladeSpeed(10);
      wtOne.setOrientation("Vertical"); 
      
      // wtOne toString
      System.out.println(wtOne.toString());
      
      // Set wtOne power to 150 then print
      wtOne.setPowerOutput(150);
      System.out.println("The power output of the WindTurbine is: " + wtOne.getPowerOutput() + "kW.");
      
      // Try and set wtOne bladeSpeed to -10 and print
      wtOne.setBladeSpeed(-10);
      System.out.println("The blade speed of the WindTurbine is: " + wtOne.getBladeSpeed());
      
      // Print WindTurbine 2's information on seperate lines
      System.out.println("WindTurbine 2:");
      System.out.println("powerOutput: " + wtTwo.getPowerOutput() + "\n" + "bladeSpeed: " + wtTwo.getBladeSpeed()
                         + "\n" + "Orientation: " + wtTwo.getOrientation());
      
      // Try and set the powerOuput of wtTwo to 0 and print
      wtTwo.setPowerOutput(0);
      System.out.println("The powerOutput of WindTurbine 2 is: " + wtTwo.getPowerOutput());
      
      // Try and set the orientation of wtTwo to Diagonal and print
      wtTwo.setOrientation("Diagonal");
      System.out.println("The orientation of WindTurbine 2 is: " + wtTwo.getOrientation());
      
      // Print wtTwo with toString
      System.out.println(wtTwo.toString());
      
   } // End Main
   
} // End Class
