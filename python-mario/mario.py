def thing():

    height = input("Height: ")

    while height < "1" or height > "8":
        height = input("Height: ")

    if height == "1":
        one = """
#  #"""
        print(one)

    elif height == "2":
        two = """
 #  #
##  ##"""
        print(two)

    elif height == "3":
        three = """
  #  #
 ##  ##
###  ###"""
        print(three)

    elif height == "4":
        four = """
   #  #
  ##  ##
 ###  ###
####  ####"""
        print(four)

    elif height == "5":
        five = """
    #  #
   ##  ##
  ###  ###
 ####  ####
#####  #####"""
        print(five)

    elif height == "6":
        six = """
     #  #
    ##  ##
   ###  ###
  ####  ####
 #####  #####
######  ######"""
        print(six)

    elif height == "7":
        seven = """
      #  #
     ##. ##
    ###  ###
   ####  ####
  #####  #####
 ######  ######
#######  #######"""
        print(seven)

    elif height == "8":
        eight = """
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########"""
        print(eight)


thing()