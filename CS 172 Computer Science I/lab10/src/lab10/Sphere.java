/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab10;

public class Sphere {

   private double radius;
	
	public Sphere( ) {
	
	   radius = 0;
	}
	
	public void setRadius( double d ) {
	   radius = d;
	}
	public double getRadius( ) {
	   return radius;
	}
	public String toString( ) {
	   return "Sphere: radius = " + radius;
	}

        public double volume( ) {
	   return 4.0 / 3.0 * Math.PI * radius * radius * radius;
	}
	public double surfaceArea ( ) {
	   return 4.0 * Math.PI * radius * radius;
	}
	public double circumference ( ) {
	   return 2 * Math.PI * radius;
	}
}