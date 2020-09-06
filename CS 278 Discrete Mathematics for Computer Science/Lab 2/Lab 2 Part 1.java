/* 
 * Name: Zachary Neeley
 * Assignment: Lab 2 Part 1
 * Description: This program will print the (~ S -> R) /\ (W \/ ~ R) /\ (M -> ~ G) /\ (G <-> S) /\ (W -> S /\ M) /\ (S -> W) truth table to console.
*/

public class Lab2Part1 {

    // Print the truth table for the statement.
    public static void main(String[] args) {
        System.out.println("(~ S -> R) /\\ (W \\/ ~ R) /\\ (M -> ~ G) /\\ (G <-> S) /\\ (W -> S /\\ M) /\\ (S -> W)");
        for (int G = 0; G<= 1; G++)
            for (int M = 0; M<= 1; M++)
                for (int R = 0; R <= 1; R++)
                    for (int S = 0; S<= 1; S++)
                        for (int W = 0; W <= 1; W++) {
                            int notS = not(S);
                            int notR = not(R);
                            int notG = not(G);
                            int tempAnd;
                            String output = "", temp = "";
                            
                            output = " " + not(S) + " " + S + "  " + arrow(notS, R) + " " + R;
                            temp = W + "  " + or(W, notR) + " " + notR + " " + R;
                            tempAnd = and(arrow(notR, R), or(W, notR));
                            output = output + "   " + tempAnd + "  " + temp + "   ";
                            
                            temp = M + "  " + arrow(M, notG) + " " + notG + " " + G;
                            output = output + "" + and(tempAnd, arrow(M, notG)) + "  " + temp + "   ";
                            
                            tempAnd = and(tempAnd, arrow(M, notG));
                            temp = G + "  " + iff(G, S) + " " + S;
                            output = output + "" + and(tempAnd, iff(G, S)) + "  " + temp + "   ";
                            
                            tempAnd = and(tempAnd, iff(G, S));
                            temp = W + "  " + arrow(W, S) + "  " + S + " " + and(arrow(W, S), M) + " " + M;
                            output = output + "" + and(tempAnd, and(arrow(W, S), M)) + "   " + temp + "   ";
                            
                            tempAnd = and(tempAnd, and(arrow(W, S), M));
                            temp = S + "  " + arrow(S, W) + " " + W;
                            output = output + "" + and(tempAnd, and(arrow(S, W), W)) + " " + temp + "\n"; 
                            
                            System.out.print(output);
        
                        }
    }
    
    // not method
    public static int not(int i) {
        if (i == 1){
            return 0;
        } else {
            return 1;
        }
    }
    
    // implied method
    public static int arrow(int L, int R) {
        if ( L == 1 && R == 1) {
            return 1;
        }
       
        if (L == 1 && R == 0) {
            return 0;
        }
       
        if (L == 0 && R == 1) {
            return 1;
           
        } else {
            return 1;
        }
    }
   
    // and method
    public static int and(int L, int R) {
        if ( L == 1 && R == 1) {
            return 1;
        }
       
        if (L == 1 && R == 0) {
            return 0;
        }
       
        if (L == 0 && R == 1) {
            return 0;
           
        } else {
            return 0;
        }
    }
    
    // Or method
    public static int or(int L, int R) {
        if ( L == 1 && R == 1) {
            return 1;
        }
       
        if (L == 1 && R == 0) {
            return 1;
        }
       
        if (L == 0 && R == 1) {
            return 1;
           
        } else {
            return 0;
        }
    }
   
    // If and only if method
    public static int iff(int L, int R) {
        if ( L == 1 && R == 1) {
            return 1;
        }
       
        if (L == 1 && R == 0) {
            return 0;
        }
       
        if (L == 0 && R == 1) {
            return 0;
           
        } else {
            return 1;
        }
    }
   
}

