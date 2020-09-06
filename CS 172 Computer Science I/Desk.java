/*
 * Desk.java
 * CS 172 - section m01
 * written by Zachary Neeley
 * date written 11/27/17
 * Uses an applet to make a desk with stuff on top of it
 * Input: None
 * Output: Applet with the needed objects drawn
 */
import java.awt.*;
import java.applet.*;

public class Desk extends Applet{
   public void paint(Graphics g){
   // Wall Light gray
   g.setColor(Color.black);
   g.fillRect(0,0,1200,400);
   
   // Name Top Left
   g.setColor(Color.black);
   g.setFont (new Font("sansserif",Font.BOLD,32));
   //g.drawString ("Zachary Neeley", 0, 50);
   // Name under desk
   g.drawString ("Zachary Neeley", 404, 604);
   
   // Window blue sky
   g.setColor(new Color(0, 179, 255));
   g.fillOval(450,54,150,150);
   
   // Window sun
   g.setColor(Color.yellow);
   g.fillOval(480,84,50,50);
   
   // Window black lines
   g.setColor(Color.black);
   g.drawOval(450,54,150,150);
   g.drawLine(525,53,525,200);
   g.drawLine(450,129,600,129);
   
   // Bottem wall line
   g.drawLine(0,397,1200,397);
   
   // Desk brown
   g.setColor(new Color(176, 120, 7));
   g.fillRect(176,280,620,270);
   g.setColor(Color.black);
   g.drawLine(176,280,146,412);
   g.drawLine(177,280,147,412);
   g.drawLine(176,548,146,648);
   g.drawLine(177,548,147,648);
   g.drawLine(794,548,764,648);
   g.drawLine(795,548,765,648);
   
   // Stuff on desk
   //Work area
   g.setColor(Color.white);
   g.fillRect(360,370,300,150);
   g.setColor(Color.black);
   g.drawRect(360,370,300,150);
   g.setFont (new Font("sansserif",Font.BOLD,20));
   g.drawString ("Work Area", 370, 400);
   g.drawLine(360,400,658,400);
   // Note book
   g.setColor(new Color(19, 124, 19));
   g.fillRect(650,432,50,100);
   g.setColor(Color.white);
   g.fillRect(659,449,30,15);
   g.setColor(Color.black);
   g.drawRect(659,449,30,15);
   // Red Ball
   g.setColor(Color.red);
   g.fillOval(200,308,25,25);
   // Empty Plate
   g.setColor(Color.white);
   g.fillOval(200,450,75,75);
   g.setColor(Color.black);
   g.drawOval(200,450,75,75);
   g.drawOval(216,460,50,50);
   // Phone
   g.setColor(Color.cyan);
   g.fillRect(500,444,25,35);
   g.setColor(Color.lightGray);
   g.fillRect(505,448,15,25);
   g.setColor(Color.black);
   g.drawRect(505,448,15,25);
   g.fillOval(508,470,10,10);
   // Pink erresor
   g.setColor(Color.pink);
   g.fillRect(574,440,10,25);
         
   } // End Paint
} // End Class
