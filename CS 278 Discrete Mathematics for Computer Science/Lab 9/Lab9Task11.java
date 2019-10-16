/**
 *
 * @author zsxc3
 */
public class Lab9Task11 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int val = g(16);
        System.out.println(val);
    }
    
    public static int g(int num) {
        if (num <= 1 ) {
            return num;
        }
        
        return g(num-1) + g(num -2) + g(num -3) + (int)Math.pow(2, num-3);
    }
    
}
