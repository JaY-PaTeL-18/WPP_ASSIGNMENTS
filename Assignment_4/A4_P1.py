# Function to check string is pallidrom or not....
def is_palindrome(s):
    # Remove spaces and convert to lowercase for uniform comparison
    s = s.replace(" ", "").lower()
    
    # Check if the string is equal to its reverse
    return s == s[::-1]             #s[::-1] --> conver "s" to reverse s  abc -> cba


def fun(str):
    opration = 0
    right = len(str) - 1     
    left = 0
    while left < right:
        if str[left] != str[right]:
            opration = opration + abs(ord(str[left]) - ord(str[right]))
        left = left + 1
        right = right - 1

    return opration            

T = int(input("Enter number of test-cases : "))

for i in range(T):
    str = input("Enter the string : ")  
    num_Of_Opratation = fun(str)
    print(num_Of_Opratation)