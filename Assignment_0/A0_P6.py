# PYTHON PROGRAM TO REVERSE OF A GIVEN NO.

# Input: A number to reverse
num = int(input("Enter a number: "))

# Reverse the number
reversed_num = 0
while num > 0:
    digit = num % 10       # Extract the last digit
    reversed_num = reversed_num * 10 + digit  # Add it to the reversed number
    num = num // 10        # Remove the last digit from the original number

print(f"The reversed number is: {reversed_num}")
