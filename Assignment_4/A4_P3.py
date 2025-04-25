import string
def is_pangram(s):
    s = s.lower()

    # This is a set thet conatain all charecters..
    alphabet = set(string.ascii_lowercase)
    # print(alphabet)

    # set from the input string, containing only letters
    charecter_in_string = set(c for c in s if c.isalpha())
    # print(letters_in_string)

    return charecter_in_string == alphabet

T = int(input("Enter number of test-cases : "))
for i in range(T):
    line = input("Enter string : ")

    if is_pangram(line):
        print("pangram.")
    else:
        print("NOT pangram.")
