# Write a program that asks the user to enter a word and then capitalizes every other 
# letter of that word. So, if the user enters rhinoceros, the program should print rHiNoCeRoS.

word = input("Enter Your word : ")

newword = ""
for i in range(len(word)):
    if i % 2 == 0:
        newword = newword + word[i].lower()
    else:
        newword = newword + word[i].upper()


print("Your new(capitalizes) word will be :",newword)
