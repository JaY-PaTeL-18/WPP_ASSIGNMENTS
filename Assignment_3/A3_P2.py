import math
# Function to check if a number is a perfect square
def is_perfect_square(n):
    if n < 0:                       # Negative numbers cannot be perfect squares
        return False
    sqrt_n = int(math.sqrt(n))      # int(math.sqrt(n))--> Calculate the integer square root 
    return sqrt_n * sqrt_n == n     # Check if squaring the result gives the original number

def check_fibo(n):
    if is_perfect_square(5*n*n + 4):  # (5*n*n + 4) or (5*n*n - 4) --> is perfect saqure then n is fibo number
        print("IsFibo")
    elif is_perfect_square(5*n*n - 4):
        print("IsFibo")
    else:
        print("IsNotFibo")


T = int(input("Enter number of test cases : "))

for i in range(T):
    n = int(input("enter number : "))
    check_fibo(n)


