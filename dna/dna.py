import sys
import re
import csv
dnaresults = []
i = 0
length = 5
count = 0
maxcount = []
found = 0
currentone = ''

if len(sys.argv) == 3:
    bigfile = str(open(sys.argv[1]).read())
    with open(sys.argv[1], 'r') as f:
        first_line = f.readline()
        first_line = first_line.rstrip("\n")
        first_line = (first_line.split(','))
    #print("Number of sequences: " + str(len(first_line)-1))

    file = str(open(sys.argv[2]).read())

    j = 0
    while j < len(first_line)-1:
        maxcount.append(0)
        j += 1

    while i < len(file):
        j = 0
        while j < len(first_line)-1:
            length = len(first_line[j+1])
            count = 0
            #print("j: " + str(j) + "  " + "  length: " + str(first_line[j+1]))
            if file[i:length+i] == first_line[j+1]:
                count += 1
                if count > maxcount[j]:
                    maxcount[j] = count
                # print(count)
                found = 1
                currentone = first_line[j+1]
                while found:
                    currentone = currentone + first_line[j+1]
                    #print('current one: ' + currentone)
                    # print('file: ' + file[i:i+length*(count+1)])
                    if file[i:i+length*(count+1)] == currentone:
                        # print("Happydays")
                        count += 1
                        if count > maxcount[j]:
                            maxcount[j] = count
                        found = 1
                    else:
                        found = 0
            j += 1
        i += 1
   # print(maxcount)
    j = 0
    textToFind = ''
    while j <= len(maxcount) - 1:
        if j == len(maxcount) - 1:
            textToFind = textToFind + str(maxcount[j])
        else:
            textToFind = textToFind + str(maxcount[j]) + ','
        j += 1
    match = 0
    with open(sys.argv[1], 'r') as f:
        for line in f:
            if (line.find(textToFind) > 0):
                match = 1
                currentline = line.split(',')
                print(currentline[0])
    if match == 0:
        print("No match")

