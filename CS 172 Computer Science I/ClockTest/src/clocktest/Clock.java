/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clocktest;

public class Clock {
    // init
    private int hour;
    private int minute;
    private int second;
    
    // constructor
    public Clock() {
        setHour(1);
        setMinute(0);
        setSecond(0);
    }
    
    // accessors
    public int getHour() {
        return hour;
    }
    
    public int getMinute() {
        return minute;
    }
    
    public int getSecond() {
        return second;
    }
    
    // mutators
    public void setHour(int x) {
        if (x >= 1 && x <= 12) {
            hour = x;
        }
    }
    
    public void setMinute(int x) {
        if (x >= 0 && x <= 59) {
            minute = x;
        }
    }
    
    public void setSecond(int x) {
        if (x >= 0 && x <= 59) {
            second = x;
        }
    }
    
    // toString
    public String toString () {
        String ans = "";
        
    }
    
}
