package lab5.task5;

public class Lab5Task5 {

    public static void main(String[] args) {
        // TODO code application logic here
        int count = 0;
        for (int i = 1; i <= 10000; i++) {
            if ( i % 3 == 0 || i % 4 == 0 || i % 7 == 0 || i % 11 == 0) {
                count++;
            }
        }
        
        System.out.println(count);
    }
        
}
