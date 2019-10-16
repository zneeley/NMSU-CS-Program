/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementpark;

public class Ride {
    private String name;
    private int time;
    private int maxRiders;
    private int numRiders;
    private int remainingTime;
    private Person riders[];
    
    public Ride(String n, int t, int m) {
        name = n;
        if (t > 0) {
            time = t;
        } else {
            time = 0;
        }
        
        if (m > 0 ) {
            maxRiders = m;
        } else {
            maxRiders = 0;
        }
        
        riders = new Person[maxRiders];
        remainingTime = 0;
        numRiders = 0;
    }
    
    public String toString() {
        StringBuilder output = new StringBuilder(name + " Riders: ");
        
        for (int i = 0; i < numRiders; i++) {
            if (riders[i] != null) {
                output.append(riders[i].getName() + ",");
            }
        }
        
        return output.toString();
    }
    
    public boolean isFull() {
        if (numRiders == maxRiders) {
            return true;
        }
        
        return false;
    }
    
    public void addRider(Person p) throws IllegalStateException{
        if (!isFull()) {
            riders[numRiders] = p; 
            
        } else {
            throw new IllegalStateException("The ride is currently full.");
        }
        
        numRiders++;
    }
    
    public void start() {
        remainingTime = time;
    }
    
    public void operate() {
        if (remainingTime > 0) {
            remainingTime--;
        }
    }
    
    public boolean isOver() {
        if (remainingTime == 0 ) {
            return true;
            
        } else {
            return false;
        }
    }
    
    public void unload() {
        System.out.println("Unloading " + toString());
        numRiders = 0;
    }
    
}
