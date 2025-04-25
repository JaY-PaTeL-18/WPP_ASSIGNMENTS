import numpy as np

# Generate N random 2D points (N >= 10)
N = 10
cartesian_points = np.random.rand(N, 2) * 100  # Random points in range [0, 100)

# Convert cartesian coordinates to polar coordinates
# r = sqrt(x^2 + y^2), theta = arctan(y / x)
x = cartesian_points[:, 0]
y = cartesian_points[:, 1]
r = np.sqrt(x**2 + y**2)
theta = np.arctan2(y, x)

polar_coordinates = np.column_stack((r, theta))

# Print results
print("Cartesian Coordinates:")
print(cartesian_points)
print("\nPolar Coordinates:")
print(polar_coordinates)