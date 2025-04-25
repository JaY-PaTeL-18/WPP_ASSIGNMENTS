def add_digits(n):                                 # n = 45893                                                   
    while n >= 10:
        n = sum(int(digit) for digit in str(n))
    return n
                                
                                                                    
num = int(input("Enter any number : "))                             

print(f"Your digit root is {add_digits(num)}")