#!/usr/bin/python
#Author : Ganesh babu
#Date   : 19-Sep-2015
#Description : This program is used to add/delete subscriber/subscription 
#              It connects to the database and insert/delete the subscribtion based on the 
#              user inputs

import MySQLdb

db = MySQLdb.connect(host="localhost", user="root", passwd="master", db="amazon") 
db.autocommit(True)
flag = 1
cur = db.cursor() 

# Use all the SQL you like
cur.execute("SELECT * FROM item")

# print all the first cell of all the rows
#for row in cur.fetchall() :
#    print row[0],row[1],row[2],row[3],row[4]


def addsub():
    try:
        name=raw_input("Enter Subscriber name :")
        email=raw_input("Enter Subscriber email :")
        item=int(input("Enter item no :"))
        t=(3,name,email,item)
        cur.execute("""INSERT INTO subscribers VALUES (%s,%s,%s,%s)""",t) 
    except MySQLdb.Error, e:
	print "Error %d: %s" % (e.args[0],e.args[1])
        return
    print "*** Subscriber Added ***"

def delsub():
    try:
        name=raw_input("Enter Subscriber name :")
        email=raw_input("Enter Subscriber email :")
        t=(name,email)
        cur.execute("""DELETE FROM subscribers WHERE name = %s AND email_id = %s """,t)
    except MySQLdb.Error, e:
	print "Error %d: %s" % (e.args[0],e.args[1])
        return
    print "*** Subscriber Removed ***"

def delitem():
    try:
        name=raw_input("Enter Subscriber name :")
        email=raw_input("Enter Subscriber email :")
        item=int(input("Enter item no :"))
        t=(name,email,item)
        cur.execute("""DELETE FROM subscribers WHERE name = %s AND email_id = %s AND subscribed_item_id = %s """,t)
    except MySQLdb.Error, e:
	print "Error %d: %s" % (e.args[0],e.args[1])
        return
    print "*** Subscribtion Removed ***"

while (1):
    print "---------- MENU -----------"
    print "1. Add Subscribtion "
    print "2. Delete Subscriber"
    print "3. UnSubscribe for an item"
    print "4. Exit"
    print "---------------------------"
    print "Please select your choise ?"
    option = input()
    if option == 1:
        addsub()
    elif option ==2:
        delsub()
    elif option ==3:
        delitem()
    elif option ==4:
	print "Thanks!"
	cur.close()
	db.close()
        break
    else:
        print "Invalid Option...Try again"


