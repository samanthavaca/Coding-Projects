import sys
from sys import argv
import re
import csv
from cs50 import SQL
db = SQL("sqlite:///students.db")
if len(sys.argv) == 2:
    housetoselect = argv[1]
    forhouse = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", housetoselect)
    for row in forhouse:
        duck = []
        for i, j in row.items():
            duck.append(str(j))

        first = duck[1]
        middle = duck[2]
        last = duck[3]
        birth = duck[5]
        if duck[2] == "None":
            print(str(first) + " " + str(last) + ", born" + " " + str(birth))
        else:
            print(str(first) + " " + str(middle) + " " + str(last) + ", born" + " " + str(birth))

