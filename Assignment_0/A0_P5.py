# PYTHON PROGRAM TO PRINT TABLE OF ANY NO.

# Input: Number for which the table is to be printed
num = int(input("Enter a number: "))
limit = int(input("Enter the limit for the table: "))  # Optional limit for how many multiples to print

# Print the multiplication table
print(f"Multiplication table of {num}:")
for i in range(1, limit + 1):
    print(f"{num} x {i} = {num * i}")
