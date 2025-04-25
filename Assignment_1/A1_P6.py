# Consider a 3-D co-ordinate space. Input 10 3-D points. Find the nearest neighbour for each
# of the points in your 3-D space and store them in a list. The final output is a list with each
# consisting of a point and its nearest neighbour. [Hint: Use distance between two points
# formula]

import math

# Function to calculate the distance between two points..
def distance(point1, point2):
    return math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2 + (point2[2] - point1[2])**2)

# Input 10 3-D points
points = [
    (1, 2, 3),
    (4, 5, 6),
    (7, 8, 9),
    (2, 3, 4),
    (5, 6, 7),
    (8, 9, 10),
    (3, 4, 5),
    (6, 7, 8),
    (9, 10, 11),
    (2, 4, 6)
]

# List to store the point and its nearest neighbor
nearest_neighbors = []

# For each point, find the nearest neighbor
for i, point in enumerate(points):
    min_distance = float('inf')  # Initialize with a large number
    nearest_point = None

    # Compare with all other points
    for j, other_point in enumerate(points):
        if i != j:  # Don't compare the point with itself
            dist = distance(point, other_point)
            if dist < min_distance:
                min_distance = dist
                nearest_point = other_point
    
    # Store the point and its nearest neighbor
    nearest_neighbors.append((point, nearest_point))

# Output the result
print("List of points with their nearest neighbors:")
for point, nearest in nearest_neighbors:
    print(f"Point {point} has nearest neighbor {nearest}")
