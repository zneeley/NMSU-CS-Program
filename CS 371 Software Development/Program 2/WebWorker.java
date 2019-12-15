/*
* Web worker: an object of this class executes in its own new thread
* to receive and respond to a single HTTP request. After the constructor
* the object executes on its "run" method, and leaves when it is done.
*
* One WebWorker object is only responsible for one client connection. 
* This code uses Java threads to parallelize the handling of clients:
* each WebWorker runs in its own thread. This means that you can essentially
* just think about what is happening on one client at a time, ignoring 
* the fact that the entirety of the webserver execution might be handling
* other clients, too. 
*
* This WebWorker class (i.e., an object of this class) is where all the
* client interaction is done. The "run()" method is the beginning -- think
* of it as the "main()" for a client interaction. It does three things in
* a row, invoking three methods in this class: it reads the incoming HTTP
* request; it writes out an HTTP header to begin its response, and then it
* writes out some HTML content for the response content. HTTP requests and
* responses are just lines of text (in a very particular format). 
*
*/

import java.net.Socket;
import java.lang.Runnable;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.TimeZone;


public class WebWorker implements Runnable
{

private Socket socket;
private String URL = ""; 

/**
* Constructor: must have a valid open socket
**/
public WebWorker(Socket s)
{
   socket = s;
}

/**
* Worker thread starting point. Each worker handles just one HTTP 
* request and then returns, which destroys the thread. This method
* assumes that whoever created the worker created it with a valid
* open socket object.
**/
public void run()
{
   System.err.println("Handling connection...");
   try {
      InputStream  is = socket.getInputStream();
      OutputStream os = socket.getOutputStream();
      readHTTPRequest(is);
      if (URL.contains(".html")) {
          writeHTTPHeader(os,"text/html");
          
      } else if (URL.contains(".ico")) {
          writeHTTPHeader(os,"image/x-icon");
          
      } else if (URL.contains(".png")) {
           writeHTTPHeader(os,"image/png");
           
      } else if (URL.contains(".jpeg") || URL.contains(".jpg")) {
           writeHTTPHeader(os,"image/jpeg");
           
      } else if (URL.contains(".gif")) {
           writeHTTPHeader(os,"image/gif");
      }
      
      writeContent(os, URL);
      os.flush();
      socket.close();
   } catch (Exception e) {
      System.err.println("Output error: "+e);
   }
   System.err.println("Done handling connection.");
   return;
}

/**
* Read the HTTP request header.
**/
private void readHTTPRequest(InputStream is)
{
   String line;
   BufferedReader r = new BufferedReader(new InputStreamReader(is));
   while (true) {
      try {
         while (!r.ready()) Thread.sleep(1);
         line = r.readLine();
         System.err.println("Request line: ("+line+")");
         if (line.length()==0) break;
         if (line.substring(0,3).equals("GET")) {
             URL = line.substring(5).split(" ")[0];
         }
      } catch (Exception e) {
         System.err.println("Request error: "+e);
         break;
      }
   }
   return;
}

/**
* Write the HTTP header lines to the client network connection.
* @param os is the OutputStream object to write to
* @param contentType is the string MIME content type (e.g. "text/html")
**/
private void writeHTTPHeader(OutputStream os, String contentType) throws Exception
{
    // Get the URL and replace all the / with \ so the os can find the file.
    String tempURL = URL;
    tempURL = tempURL.replace("/","\\");
    File directory = new File(tempURL);
    
    Date d = new Date();
    DateFormat df = DateFormat.getDateTimeInstance();
    df.setTimeZone(TimeZone.getTimeZone("GMT"));
    
    // Check to see if the request is there if so than return code 200 if not
    // than return code 404
    if (directory.isFile()) {
        os.write("HTTP/1.1 200 OK\n".getBytes());
    } else {
        os.write("HTTP/1.1 404 Not Found\n".getBytes());
    }
    os.write("Date: ".getBytes());
    os.write((df.format(d)).getBytes());
    os.write("\n".getBytes());
    os.write("Server: Zach's very own server\n".getBytes());
    //os.write("Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT\n".getBytes());
    //os.write("Content-Length: 438\n".getBytes()); 
    os.write("Connection: close\n".getBytes());
    os.write("Content-Type: ".getBytes());
    os.write(contentType.getBytes());
    os.write("\n\n".getBytes()); // HTTP header ends with 2 newlines
    return;
}

/**
* Write the data content to the client network connection. This MUST
* be done after the HTTP header has been written out.
* @param os is the OutputStream object to write to
**/
private void writeContent(OutputStream os, String incomingURL) throws Exception
{
    // Replace the / character with the \ so java can search the file directory
    incomingURL = incomingURL.replace("/","\\");
    File directory = new File(incomingURL);
    
    //Get current date
    SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
    Date date = new Date();
    
    // If the call is for the favicon just ignore the call
    if (incomingURL.contains("favicon.ico") || incomingURL.contains(".png") || incomingURL.contains(".jpeg") || incomingURL.contains(".jpg") || incomingURL.contains(".gif")){
        byte[] encodedFile = Files.readAllBytes(Paths.get(incomingURL));
        os.write(encodedFile);
        
    } else {
        
    
        // Check to see if the file esists if so encode the file and send to browser.
        // If the file doesnot exists than send the error 404 message.
        if (directory.isFile()) {
            
            // Encode the file contents into bytes
            byte[] encodedFile = Files.readAllBytes(Paths.get(incomingURL));
            
            // Convert the bytes into string passing the byte array with the characterset
            // need to decode the byte array.
            String fileContents = new String(encodedFile, StandardCharsets.UTF_8); 
            
            // Replace the <cs371date> tag
            String dateTag = dateFormat.format(date);
            fileContents = fileContents.replace("<cs371date>", dateTag);
            
            
            // Replace the <cs371server> tag
            String serverTag = "Zach's AMAZING WORLD EATING SERVER";
            fileContents = fileContents.replace("<cs371server>", serverTag);
            
            // Send the bytes to the web browser
            os.write(fileContents.getBytes());
            
        } else {
            // Set the location for the error 404 page 
            String error404 = "error404.html";
            
            // Encode the file contents into bytes
            byte[] encodedFile = Files.readAllBytes(Paths.get(error404));
            
            // Convert the bytes into string passing the byte array with the characterset
            // need to decode the byte array.
            String fileContents = new String(encodedFile, StandardCharsets.UTF_8);
            
            // Send the bytes to the web browser
            os.write("<center>Oh no! This should have stuff here!</center>".getBytes());
            os.write(fileContents.getBytes());
            
        }
    }
}

} // end class
