/*
 * Pie.java
 * CS 172 - section m01
 * written by Zachary Neeley
 * date written 11/27/17
 * Uses an applet to make a pie chart with 8 different colored parts
 * Input: None
 * Output: Applet with the needed objects drawn
 */
import java.awt.*;
import java.applet.*;

public class Pie extends Applet{
   public void paint(Graphics g){
      // Outline of the pie chart      
      Graphics2D g2 = (Graphics2D) g;
      g2.setStroke(new BasicStroke(2));
      g2.setColor(Color.black);
      g2.drawOval(49,49,301,302);
      
      // Each part of the circle
      // Red part
      g.setColor(Color.red);
      g.fillArc(50,50,300,300,0,45);
      // Yellow Part
      g.setColor(Color.yellow);
      g.fillArc(50,50,300,300,45,45);
      // Blue Part
      g.setColor(Color.blue);
      g.fillArc(50,50,300,300,90,45);
      // Green Part
      g.setColor(Color.green);
      g.fillArc(50,50,300,300,135,45);
      // Pink Part
      g.setColor(Color.pink); 
      g.fillArc(50,50,300,300,180,45);
      // Cyan Part
      g.setColor(Color.cyan);
      g.fillArc(50,50,300,300,225,45);
      // Magenta Part
      g.setColor(Color.magenta);
      g.fillArc(50,50,300,300,270,45);
      // Orange Part
      g.setColor(Color.orange);
      g.fillArc(50,50,300,300,-45,45);
      
      // Lines Splitting the parts
      g.setColor(Color.black);
      g.drawLine(200,200,50,200);
      g.drawLine(200,200,96,95);
      g.drawLine(200,200,200,50);
      g.drawLine(200,200,305,95);
      g.drawLine(200,200,350,200);
      g.drawLine(200,200,305,305);
      g.drawLine(200,200,200,350);
      g.drawLine(200,200,96,307);
      
      // Name box background
      g.setColor(Color.blue);
      g.fillRect(0, 350, 350, 50);
      // Name
      g.setColor(Color.red);
      g.setFont (new Font("sansserif",Font.BOLD,32));
      g.drawString ("This is a test", 0, 400);
      
   } // End Paint
} // End Class
