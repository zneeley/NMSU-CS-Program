/* 
 * Name: Zachary Neeley
 * Assignment: Lab 2 Part 2 Ep 2
 * Description: This program will the ((∀x, P(x)) ∧ (∀x, Q(x, x))) → (∀x,(P(x) → (∀y,(Q(x, y) → Q(y, x))))) and make it false.
*/

public class Lab2Part2Eq2Counter {

   static boolean []P = {true, true};
   static boolean [][]Q = {{true, false},{true,true}};
   
   public static void main (String[] args) {
   	System.out.println("The output is: " + testRun2());
   	}
   
   public static boolean testRun2() {
   	for (int x = 0; x < 2; x++)
   	   if(!PxLoop(x))
   		   return true;
   	return false;
   }
   public static boolean p(int x) {
   	return P[x];
   }
   
   public static boolean q(int x, int y){
   	return Q[x][y];
   }
   
   public static boolean PxLoop(int x) {
   	for(int y = 0; y < 2; y++)
   		if(QxLoop(x)) {
   			return true;
   		} else {
   			if(compareQ(x) == false) {
   				return false;
   			}
   		}
   	 
   	return true;
   }
     public static boolean QxLoop(int x){
   	  for(int y = 0; y < 2; y++)
   		  if(!q(x,x)) return false;
   		  return true;
   	  }
    
    
   	 
     public static boolean compareQ(int x) {
   	  for(int y = 0; y < 2; y++)
   		  if(q(x,y) != q(y,x))
   			  return false;
   	      return true;
   		 
   	 
     }
       
   }
     public static boolean compareQ(int x) {
   	  for(int y = 0; y < 2; y++)
   		  if(q(x,y) != q(y,x))
   			  return false;
   	      return true;
   		 
   	 
     }
       
   }
   




