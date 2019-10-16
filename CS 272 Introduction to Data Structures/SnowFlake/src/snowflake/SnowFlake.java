/**
 * This file draws a snowFlake in a JPanel using recursions to complete the take.
 * @since 10/25/2018
 * @author Zach Neeley
 */
package snowflake;

import java.awt.*;
import javax.swing.*;

public class SnowFlake extends JPanel {
    
    // Max levels for the nowflake
    private static int maxLevel = 30;
   
    /**
     * paintComponent will create the needed graphics component
     * @param g Graphics component
     */
    public void paintComponent ( Graphics g ) {
      setBackground(Color.white);
      snowFlake( g, Color.blue, 3, 150, 275, 275, 20);
    } 
    
    /**
     * Main function creates the JPanel 
     * @param args 
     */
    public static void main(String[] args){

        // Setup the new frame called snowFlake
        JFrame frame = new JFrame("Snowflake");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Create the panel that goes into the frame
        SnowFlake snowFlakePanel = new SnowFlake();
        frame.add(snowFlakePanel);
        
        // Set the size of the panel and allow it to be seen
        frame.setSize(1000, 1000);
        frame.setVisible(true);
        
    } // end main
    
    /**
     * Method snowFlake recursively draws a snowFlake in a JPanel
     * @param g Graphics component G
     * @param color Graphics color
     * @param level Amount of levels in the call
     * @param lineLength Length of the lines drawn
     * @param centerX X Cord center
     * @param centerY Y Cord center 
     * @param spokeNums Number of spokes
     */
    public void snowFlake(Graphics g, Color color, int level, int lineLength, int centerX, int centerY, int spokeNums) {
        // init
        int x,y, xNew, yNew;
        int incrementAngle, currentAngle;
        
        // Set the new angles
        incrementAngle = 360 / spokeNums;
        currentAngle = 0;
        
        // Set the beginning x and y
        x = centerX;
        y = centerY;
        
        if (level > 0) {
            
            g.setColor(color);
            
            // Recursive steps
            for (int i = 0; i < spokeNums; i++) {
                x = centerX;
                y = centerY;
                
                // Get the new x and y cords
                xNew = (int)(centerX + lineLength * Math.cos(currentAngle * Math.PI / 180));
                yNew = (int)(centerY - lineLength * Math.sin(currentAngle * Math.PI / 180));
                
                // Draw the new line
                g.drawLine(x, y, xNew, yNew);
                
                // Change the angle
                currentAngle = currentAngle + incrementAngle;
                
                // Recursively call the new snowFlake
                snowFlake(g, color, level-1, (int)(lineLength / 4), xNew, yNew, spokeNums);
                snowFlake(g, color, level-2, (lineLength / 8), ((xNew + centerX) / 2), ((yNew + centerY) / 2), spokeNums);
                
            } // end recursive step
        } // end if
    } // end snowFlake 
} // end class
