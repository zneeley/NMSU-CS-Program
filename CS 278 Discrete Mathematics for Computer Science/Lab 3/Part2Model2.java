/*
 * Name: Zachary Neeley	
 * Date: 2/6/19
 * Assignment: Lab 3, this file will model the expression ((∀x,(P(x) → (Q(x) ∨ R(x)))) ∧ (∃x,(Q(x) ∧ R(x)))) → (∃x,(P(x) ∧ R(x))) 
 */

public class Part2CounterModel {

	// init
    static boolean[] P = {false, false, true, true};
    static boolean[] Q = {true, false, true, true};
    static boolean[] R = {true, false, false, true};

    public static void main(String[] args) {
		// print out the output of the expression
        System.out.print(arrow(and(pimplyqandr(), qandrexists()), (pandrexists())));
    
    }

	// Return the index of p[x]
    public static boolean p(int x) {
        return P[x];
    }

	// Return the index of q[x]
    public static boolean q(int x) {
        return Q[x];
    }

	// Return the index of r[x]
    public static boolean r(int x) {
        return R[x];
    }

	// Loop through all the possible values for p(X)
    public static boolean pxLoop() {
        for (int y = 0; y < 2; y++) {
            if (p(y)) {
                return true;
            }
        }
        return false;
    }

	// Loop through all the possible values for q(X)
    public static boolean qxLoop() {
        for (int y = 0; y < 2; y++) {
            if (q(y)) {
                return true;
            }
        }
        return false;
    }

	// Use this for p impy r and r 
    public static boolean pimplyqandr(){
        for (int x = 0; x < P.length; x++) {
            if (!arrow(p(x),r(x) || q(x))) {
                return false;
            }
        }
        return true;
    }
	
	// Use this for the p and r to see if they exist
    public static boolean pandrexists() {
        for (int x = 0; x < P.length; x++) {
            if (r(x) && p(x)) {
                return true;
            }
        }
        return false;
    }

	// Use this for the q and r to see if they exist
    public static boolean qandrexists() {
        for (int x = 0; x < Q.length; x++) {
            if (r(x) && q(x)) {
                return true;
            }
        }
        return false;
    }

	// Use this for the "and" in the expression
    public static boolean and(boolean L, boolean R) {
        if (R == true & L == true) {
            return true;
        }
        if (R == true & L == false) {
            return false;
        }
        if (R == false & L == true) {
            return false;
        } else {
            return false;
        }
    }

	// Use this for the "or" in the expression
    public static int or(int L, int R) {
        if (R == 1 & L == 1) {
            return 1;
        }
        if (R == 1 & L == 0) {
            return 1;
        }
        if (R == 0 & L == 1) {
            return 1;
        } else {
            return 0;
        }
    }

	// Use this for the "imply" in the expression
    public static boolean arrow(boolean L, boolean R) {
        if (R == true & L == true) {
            return true;
        }
        if (R == true & L == false) {
            return true;
        }
        if (R == false & L == true) {
            return false;
        } else {
            return true;
        }

    }

}
