# PYTHON PROGRAM TO FIND THE FACTORIAL OF A NUMBER.

def factorial(n):
    # If n is 0 or 1, factorial is 1
    if n == 0 or n == 1:
        return 1
    else:
        result = 1
        for i in range(1, n + 1):
            result *= i     # result = result * i
        return result

# Input from user
num = int(input("Enter a number: "))

# Check if the input is a non-negative integer
if num < 0:
    print("Factorial is not defined for negative numbers.")
else:
    # Calculate and display the factorial
    print(f"The factorial of {num} is {factorial(num)}.")
