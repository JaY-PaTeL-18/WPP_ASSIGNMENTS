import numpy as np

# Create a sample numpy array
arr = np.array(["apple", "banana", "cherry", "date", "elderberry"])

# Function to format strings
def format_strings(array):
    centered = np.char.center(array, 15, fillchar='_')
    left_justified = np.char.ljust(array, 15, fillchar='_')
    right_justified = np.char.rjust(array, 15, fillchar='_')
    
    return centered, left_justified, right_justified

# Format the strings
centered, left_justified, right_justified = format_strings(arr)

# Display the results
print("Original Array:")
print(arr)
print("\nCentered:")
print(centered)
print("\nLeft-Justified:")
print(left_justified)
print("\nRight-Justified:")
print(right_justified)