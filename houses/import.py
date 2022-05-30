import sys
import re
import csv
from cs50 import SQL
db = SQL("sqlite:///students.db")
list = []
# Split name function


def splitname(fullname):
    names = fullname.split()
    # Check to see if middle name present
    return names if len(names) >= 3 else[names[0], None, names[1]]


if len(sys.argv) == 2:
    with open(sys.argv[1], 'r') as csv_file:
        read = csv.DictReader(csv_file)

        # Analyze rows
        for row in read:
            names = splitname(row["name"])
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], row["house"], row["birth"]
                       )
