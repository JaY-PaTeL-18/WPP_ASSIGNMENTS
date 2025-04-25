# Take numbers from 1 to 10000. Create equivalence classes for modulo 5 on this set of
# numbers. Check the validity of your equivalence classes. [Hint: the union of all equivalence
# classes should be the original set/list.]


# Define the range of numbers
numbers = range(1, 10001)

# Create equivalence classes for modulo 5
equivalence_classes = {i: [] for i in range(5)}
for number in numbers:
    equivalence_classes[number % 5].append(number)

# Check the validity of equivalence classes
union_of_classes = []
for key in equivalence_classes:
    union_of_classes.extend(equivalence_classes[key])

# Sort the union to compare with the original set
union_of_classes.sort()

# Check if the union of all equivalence classes is equal to the original set
is_valid = list(numbers) == union_of_classes

print(f"Equivalence classes are valid: {is_valid}")