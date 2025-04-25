# You are a student in a class of 10. Your class teacher assigns you a task of entering the
# names of all the students in the class. You finally want to display the names given the
# condition that the maximum allowed characters in a name is 15. As a fun task, reverse the
# names and display them. [Hint: Slicing works when you are selecting maximum characters]

names = []
while(True):
    name = input("Enter name or enter 0 for exit: ")
    if name=='0':
        break
    if len(name)>15:
        print("Value should be less than 15")
    else: names.append(name)

for name in names:
    print(name[::-1])