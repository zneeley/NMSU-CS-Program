/*
 * Name: Zachary Neeley
 * Date: 4/3/2019
 * Assignment: Lab 9 Task 5
*/

public class Lab9Task5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int count = 0;
        String[] a = new String[65536];
        String start ="0", add = "1", temp = "";
        
        for (int i = 0; i < 65536; i++) {
            
            // Add the 2 strings together
            temp = addBinary(start, add);
            
            // Store temp into a[i]
            a[i] = temp;
            
            // Make start the value in temp
            start = temp;
            
            // Check to see if the string in a[i] contains 000 at any point, if
            // so add 1 to count
            if (a[i].contains("000")) {
                count++;
            } // end if
            //System.out.println(a[i]);
            
        } // end for
        
        System.out.println(count);
        
        
    } // end main
    public static String addBinary(String input0, String input1){

        // Use as radix 2 because it's binary    
        int number0 = Integer.parseInt(input0, 2);
        int number1 = Integer.parseInt(input1, 2);
        
        // Add the two dinary values
        int sum = number0 + number1;
        
        //Return the answer as a binary value
        return Integer.toBinaryString(sum); 
        
    } // end addBinary

    
}
