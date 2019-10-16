/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementpark;

public class Person {
    private String name;
    
    public Person(String n) {
        setName(n);
    }
    
    public void setName(String n) {
        name = n;
    }
    
    public String getName() {
        return name;
    }
}
