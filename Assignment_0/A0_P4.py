# PYTHON PROGRAM TO SWAP TWO VARIABLES WITHOUT USING THIRD VARIABLE

# Input: Two variables
a = int(input("Enter the first number(a): "))
b = int(input("Enter the second number(b): "))

# Swapping without using a third variable
a, b = b, a

# Output the swapped values
print(f"After swapping: a = {a}, b = {b}")
