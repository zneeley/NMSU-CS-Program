import java.util.Scanner;

public class Lab6Task3 {

    public static void main(String[] args) {
        // TODO code application logic here
        int a, b, temp;
        Scanner Scan = new Scanner(System.in);
        
        System.out.println("Enter A Value: ");
        a = Scan.nextInt();
        
        System.out.println("Enter A Value: ");
        b = Scan.nextInt();
        
        while (b > 0 ) {
            temp = a;
            a = b;
            b = (temp % b);       
        }
        
        System.out.println(a);
    }
    
}
