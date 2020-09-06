/* 
 * Name: Zachary Neeley
 * Assignment: Lab 2 Part 2 Ep 1
 * Description: This program will the ((∀x p(x)) → (∀x q(x))) → ∀x (p(x) → q(x)) and make it true.
*/

public class Lab2Part2Eq1 {
    

    static boolean[] P = {
        true,
        true
    };
    
    static boolean[] Q = {
        true,
        false
    };

    public static void main(String[] args) {
        System.out.println("The model to the problem is: " + W());
    }

    public static boolean W() {
        for (int x = 0; x < 2; x++)
            if (!PxLoop(x))
            return true;
    return false;
    }
    
    public static boolean p(int x) {
        return P[x];
    }

    public static boolean q(int x) {
        return Q[x];
    }

    public static boolean PxLoop(int x) {
        for (int y = 0; y < 2; y++)
            if (!QxLoop(x)) return false;
    return true;

    }
    public static boolean QxLoop(int x) {
        for (int y = 0; y < 2; y++)
            if (!dualLoop(x)) return false;
        return true;
    }


    public static boolean dualLoop(int x) {
    for (int y = 0; y < 2; y++)
        if (!P[1] && !Q[x])
            return true;
    return false;
    }
    
}
