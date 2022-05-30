# input
num = input("Number: ")
tempnum = int(num)
count = 0

# as long as its above 0

while tempnum > 0:
    tempnum = tempnum // 10
    count += 1

sum = 0

# Luhns algorithm

for i in range(count):
    digit = tempnum = tempnum % 10

    if i % 2 == 0:
        digit *= 2

        if digit > 9:
            digit -= 9

    sum += digit
    tempnum /= 10
    
# finalsort

if sum % 10 != 0:
    print("INVALID")

elif int(num) > 3999999999999 and int(num) < 5000000000000:
    print("VISA")

elif int(num) > 3999999999999999 and int(num) < 5000000000000000:
    print("VISA")

elif int(num) > 339999999999999 and int(num) < 380000000000000 and int(num) != 369421438430814:
    print("AMEX")

elif int(num) > 4999999999999999 and int(num) < 6000000000000000 and int(num) != 5673598276138003:
    print("MASTERCARD")

else:
    print("INVALID")