phrase = str(input("Text: "))

l = 200
count = 0
index = 0
index1 = 0
countletters = 0
countothers = 0
countwords = 1
onecharacter = 0
finall = 0
finals = 0
length = len(phrase)
for i in range(length):
    if phrase[i].isalpha() == True:
        countletters = countletters + 1
for i in range(length):
    if phrase[i].isspace() == True:
        countwords = countwords + 1
for i in range(length):
    if phrase[i] == "?" or phrase[i] == "." or phrase[i] == "!":
        count = count + 1
index1 = float(100 / countwords)
L = float(countletters * index1)
S = float(count * index1)
form = float(0.0588 * L - 0.296 * S - 15.8)

if form >= 15.5:

    print("Grade 16+")

elif form <= 1.49:

    print("Before Grade 1")

else:
    print("Grade", round(form))