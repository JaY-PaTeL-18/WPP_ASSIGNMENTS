import pandas as pd

# Given pandas series
s = pd.Series(['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])

# Convert to upper case
upper_case = s.str.upper()

# Convert to lower case
lower_case = s.str.lower()

# Find the length of each string
string_length = s.str.len()

# Display the results
print("Original Series:")
print(s)
print("\nUpper Case:")
print(upper_case)
print("\nLower Case:")
print(lower_case)
print("\nString Lengths:")
print(string_length)