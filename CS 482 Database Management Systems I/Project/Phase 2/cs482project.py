# -*- coding: utf-8 -*-
import os
import sys
import time
import MySQLdb as db
from dotenv import load_dotenv 
load_dotenv() 
import tkinter as tk 
from tkinter import *

# Need GUI variables
gui = tk.Tk() 
gui.title('Project Phase 2 - ZN') 
gui.focus_set()
file = StringVar()
file2 = StringVar()
sqlQueryInput = StringVar()

# popupMSG - used to show messages with an ok box
def popupMSG(msg):
    popup = tk.Tk()
    popup.wm_title("Message!")
    popup.focus_set()
    label = tk.Label(popup, text=msg)
    label.pack(side="top", fill="x", pady=10)
    B1 = tk.Button(popup, text="Okay", command = popup.destroy)
    B1.pack()
    popup.mainloop()

# all_children - will get all the current tkinter widgets
def all_children (gui) :
    _list = gui.winfo_children()

    for item in _list :
        if item.winfo_children() :
            _list.extend(item.winfo_children())

    return _list

# clearWindow - will destroy any widgets currently on screen
def clearWindow():
    # Clear anything on screen
    widget_list = all_children(gui)
    for item in widget_list:
        item.destroy()
    
# singleInsertionGUI - GUI wrapper 
def singleInsertionGUI():
    clearWindow()
    
    # Create the new window needed
    labelMsg3 = Label(gui, text ='Please input the data file name.\nExample: Games.txt\n')
    labelMsg3.pack()
    
    inputBox = Entry(gui, textvariable=file).pack()

    
    button6 = tk.Button(gui, text='Submit File', width=25, command=singleInsertion)
    button6.pack()
    button7 = tk.Button(gui, text='Back To Main Menu', width=25, command=main)
    button7.pack()
    
    labelMsg4 = Label(gui, text ='\n\nNOTE: The program will stop responding when running insertion statements.\nJust let it run the commands.\n')
    labelMsg4.pack()

    
# singleInsertion - proforms the needed steps to issue inserts into the database
def singleInsertion():
    
    # Connect to the database using the .env file
    connection = db.connect(host=os.getenv('HOST'), port=int(os.getenv('PORT')), user=os.getenv('USER'), password=os.getenv('PASSWORD'), db=os.getenv('DB_NAME'))
    cursor = connection.cursor()
    
    # Prompt for the file to be used for single insertion
    
    fileTXT = file.get()
    
    # Get the current system time for calculation later
    timeStart = time.time()
    
    # Setup error list if needed
    errorScrollbar = Scrollbar(gui)
    errorScrollbar.pack(side = RIGHT, fill = Y) 
    errors = Listbox(gui, yscrollcommand = errorScrollbar.set, width = 100)
    
    # Create the needed insertion statements and issue them one at a time for mySQL
    with open(fileTXT, 'r') as data:
        for row in data:
            row = row.strip().strip('\n').split(',')
            
            # Create the sql statements needed for the insert
            sqlStmt = sqlInsertFormat(fileTXT, row)
            
            # Issue the sql insert
            try: 
                cursor.execute(sqlStmt)
                connection.commit()
                
            except(db.Error, db.Warning) as err:
                errors.insert(END, str(err))
                connection.rollback()
                
    # Show Errors if needed
    errors.pack(side = LEFT, fill = BOTH)
    errorScrollbar.config(command = errors.yview)
    
    # Print Results and close sql connections
    popupMSG("\nTask Completed. \n Took {} Seconds \n".format(round(time.time() - timeStart)))
    connection.close()  
    main()

# sqlInsertFormat - will format the needed insert statments                 
def sqlInsertFormat(fileTXT, row):
    # Check to see what the file passed was.
    if fileTXT == "Players.txt" or fileTXT == "players.txt" or fileTXT == "Players1.txt" or fileTXT == "players1.txt" or fileTXT == "Players2.txt" or fileTXT == "players2.txt" or fileTXT == "Players3.txt" or fileTXT == "players3.txt":
        sqlStmt = "INSERT INTO players (PlayerID, Name, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES ("+ row[0] +','+ formatString(row[1]) +','+ formatString(row[2]) +','+ formatString(row[3]) +','+ row[4] +','+ row[5] +','+ row[6] + ");"
    elif fileTXT == "Games.txt" or fileTXT == "games.txt":
        sqlStmt = "INSERT INTO games (GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES ("+ row[0] +','+ formatString(row[1]) +','+ formatString(row[2]) +','+ formatString(row[3]) +','+ row[4] +','+ row[5] + ");"
    elif fileTXT == "Play.txt" or fileTXT == "play.txt":
        sqlStmt = "INSERT INTO play (PlayerID, GameID) VALUES ("+ row[0] +','+ row[1] + ");"
    else:
        print("ERROR: File " + fileTXT + " cannot be read or does not exist in the currents directory!\n") 
    
    return sqlStmt         

# multiRowInsertionGUI - GUI wrapper 
def multiRowInsertionGUI():
    clearWindow()
    
    # Create the new window needed
    labelMsg3 = Label(gui, text ='Please input the data file name.\nExample: Games.txt\n')
    labelMsg3.pack()
    
    inputBox2 = Entry(gui, textvariable=file2).pack()

    
    button6 = tk.Button(gui, text='Submit File', width=25, command=multiRowInsertion)
    button6.pack()
    button7 = tk.Button(gui, text='Back To Main Menu', width=25, command=main)
    button7.pack()
    
    labelMsg4 = Label(gui, text ='\n\nNOTE: The program will stop responding when running insertion statements.\nJust let it run the commands.\n')
    labelMsg4.pack()

# multiRowInsertion - proforms the needed steps to issue inserts into the database 
def multiRowInsertion():
    #connect to database using env credentials
    connection = db.connect(host=os.getenv('HOST'), port=int(os.getenv('PORT')), user=os.getenv('USER'), password=os.getenv('PASSWORD'), db=os.getenv('DB_NAME'))
    cursor = connection.cursor()
    
    # Get the file name from the input box
    fileTXT = file2.get()
    
    # Get the current time for calculation later 
    timeStart = time.time()

    # Create the main sql statement 
    with open(fileTXT,'r') as data:   
        sql = MultiRowDef(fileTXT)
        for row in data:
            row = row.strip().strip('\n').split(',')
            sql += MultiRowText(row, fileTXT)
            
    # Add a ; to the end of the sql statement
    sql = sql[:-2] + ";"
    try:
        cursor.execute(sql)
        connection.commit()
    except:
        connection.rollback()
        
    # Print Results and close sql connections
    popupMSG("\nTask Completed. \n Took {} Seconds \n".format(round(time.time() - timeStart)))
    connection.close()  
    main()
    
# MultiRowText - will add the data to the insertion statements
def MultiRowText(row, file):
    # Check to see what file the user has selected
    if file == "Players.txt" or file == "players.txt" or file == "Players1.txt" or file == "players1.txt" or file == "Players2.txt" or file == "players2.txt" or file == "Players3.txt" or file == "players3.txt":
        sql = "("+ row[0] +','+ formatString(row[1]) +','+ formatString(row[2]) +','+ formatString(row[3]) +','+ row[4] +','+ row[5] +','+ row[6] + "), "
    elif file == "Games.txt":
        # Check to see if the dates are allowed by the database if so add the data to the sql statement, if it is allowed add the data to the sql statement
        Date = formatString(row[1])
        
        if ('-2-30' in Date) or ((int(Date[1:5]) % 4 != 0) and '-2-29' in Date):
            sql=''
        else:
            sql = "("+ row[0] +','+ formatString(row[1]) +','+ formatString(row[2]) +','+ formatString(row[3]) +','+ row[4] +','+ row[5] + "), "
    elif file == "Play.txt":
        sql = "("+ row[0] +','+ row[1] + "), "

    return sql

# MultiRowDef - will format the beginning insert statments 
def MultiRowDef(file):
    # Check to see what the user input was and create the needed sql statement beginnings if needed.
    if file == "Players.txt" or file == "players.txt" or file == "Players1.txt" or file == "players1.txt" or file == "Players2.txt" or file == "players2.txt" or file == "Players3.txt" or file == "players3.txt":
        sql = "INSERT INTO players (PlayerID, Name, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES "
    elif file == "Games.txt":
        sql = "INSERT INTO games (GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES "
    elif file == "Play.txt":
        sql = "INSERT IGNORE INTO play (PlayerID, GameID) VALUES "

    return sql

# deleteTableGUI - GUI wrapper
def deleteTableGUI():
    clearWindow()
    
    labelMsg6 = Label(gui, text ='Please select which table you would like to delete.\n\n')
    labelMsg6.pack()
    
    # Create the needed buttons
    button6 = tk.Button(gui, text='Players', width=25, command =lambda: deleteTable("DELETE FROM Players"))
    button6.pack()
    button7 = tk.Button(gui, text='Games', width=25, command =lambda: deleteTable("DELETE FROM Games"))
    button7.pack()
    button8 = tk.Button(gui, text='Play', width=25, command =lambda: deleteTable("DELETE FROM Play"))
    button8.pack()
    button9 = tk.Button(gui, text='Back to Main Menu', width=25, command=main)
    button9.pack()
    
    labelMsg7 = Label(gui, text ='\n')
    labelMsg7.pack()

# deleteTable - will delete a table's data from the sql tables
def deleteTable(option):
    # Connect to the database using the .env file
    connection = db.connect(host=os.getenv('HOST'), port=int(os.getenv('PORT')), user=os.getenv('USER'), password=os.getenv('PASSWORD'), db=os.getenv('DB_NAME'))
    cursor = connection.cursor()
    
    # Prompt for input from user
    sqlStmt = option

        
    # Get the current system time for calculation later
    timeStart = time.time()
    
    # Issue the sql insert
    try: 
        cursor.execute(sqlStmt)
        connection.commit()
                
    except(db.Error, db.Warning) as err:
        messageVar = Message(main, text = err)
        messageVar.pack()
        connection.rollback()
        
    finally:
        # Print Results and close sql connections
        popupMSG("\nTask Completed. \n Took {} Seconds \n".format(round(time.time() - timeStart)))
        connection.close()
        main()
    
# sqlQueryGUI - GUI Wrapper
def sqlQueryGUI():
    clearWindow()
    
    # Create the new window needed
    labelMsg3 = Label(gui, text ='Please a SQL query.\nExample: SELECT * FROM Games\n')
    labelMsg3.pack()
    
    inputBox = Entry(gui, textvariable=sqlQueryInput, width = 75).pack()

    
    button6 = tk.Button(gui, text='Submit Query', width=25, command=sqlQuery)
    button6.pack()
    button7 = tk.Button(gui, text='Back To Main Menu', width=25, command=main)
    button7.pack()
    
    labelMsg4 = Label(gui, text ='\n')
    labelMsg4.pack()
    
# sqlQuery - will query the data with a given statement from the user  
def sqlQuery():
    # Connect to the database using the .env file
    connection = db.connect(host=os.getenv('HOST'), port=int(os.getenv('PORT')), user=os.getenv('USER'), password=os.getenv('PASSWORD'), db=os.getenv('DB_NAME'))
    cursor = connection.cursor()
    
    # Prompt for an sql query
    sqlStmt = sqlQueryInput.get()
    
    # Get the current system time for calculation later
    timeStart = time.time()
    
    # Setup output box
    outputScrollbar = Scrollbar(gui)
    outputScrollbar.pack(side = RIGHT, fill = Y) 
    output = Listbox(gui, yscrollcommand = outputScrollbar.set, width = 100)
    
    # Issue sql query
    try:    
        cursor.execute(sqlStmt)
        connection.commit()
        
        for x in cursor:
            output.insert(END, str(x))
            
    except(db.Error, db.Warning) as err:
        messageVar = Message(main, text = err)
        messageVar.pack()
        connection.rollback()
    
    # Show output if needed
    output.pack(side = LEFT, fill = BOTH)
    outputScrollbar.config(command = output.yview)
    
    # Print Results and close sql connections
    popupMSG("\nTask Completed. \n Took {} Seconds \n".format(round(time.time() - timeStart)))
    connection.close()
    main()
    
def exitProgram():
    clearWindow()
    gui.destroy()
    sys.exit()
    
# formatStringSingle - will format the strings needed for single insertion
def formatString(string):
    string = "\'" + string.lstrip() + "\'"
    return string   

def main():
    # Clear any widgets needed
    clearWindow()
    
    #interface for selecting type of insertion
    labelMsg = Label(gui, text ='Please select an option by clicking the corresponding button.\n\n')
    labelMsg.pack()
    
    # Create the needed buttons
    button1 = tk.Button(gui, text='Single Insertion', width=25, command=singleInsertionGUI)
    button1.pack()
    button2 = tk.Button(gui, text='Multi Insertion', width=25, command=multiRowInsertionGUI)
    button2.pack()
    button3 = tk.Button(gui, text='Delete Data in Table', width=25, command=deleteTableGUI)
    button3.pack()
    button4 = tk.Button(gui, text='Run SQL Query', width=25, command=sqlQueryGUI)
    button4.pack()
    button5 = tk.Button(gui, text='Exit Program', width=25, command=exitProgram)
    button5.pack()
    
    # Padding
    labelMsg = Label(gui, text ='\n')
    labelMsg.pack()
    
    
if __name__ == '__main__':
    main()
   
gui.mainloop() 