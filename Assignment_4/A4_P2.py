import math
# Function to check if a number is a perfect square
def is_perfect_square(n):
    if n < 0:                       # Negative numbers cannot be perfect squares
        return False
    sqrt_n = int(math.sqrt(n))      # int(math.sqrt(n))--> Calculate the integer square root 
    return sqrt_n * sqrt_n == n     # Check if squaring the result gives the original number

def fun(a,b): 
    count = 0
    for i in range(b-a+1):   
        if(is_perfect_square(a)):          
            count = count + 1
            a = a + 1                            
        else:
            a = a + 1
    return count               

T = int(input("Enter number of test-cases : "))

for i in range(T):
    a, b = map(int, input("").split())
    result = fun(a,b)
    print(result)


