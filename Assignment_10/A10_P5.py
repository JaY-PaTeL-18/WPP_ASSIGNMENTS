import numpy as np

import matplotlib.pyplot as plt

def f(x):
    # Define the polynomial function here
    return x**3 - 6*x**2 + 11*x - 6  # Example: (x-1)(x-2)(x-3)

def bisection_method(func, a, b, tol=1e-6, max_iter=100):
    if func(a) * func(b) >= 0:
        raise ValueError("The function must have opposite signs at a and b.")
    
    iterations = []
    for i in range(max_iter):
        c = (a + b) / 2
        iterations.append(c)
        
        if abs(func(c)) < tol or (b - a) / 2 < tol:
            break
        
        if func(a) * func(c) < 0:
            b = c
        else:
            a = c
    
    return c, np.array(iterations)

# Initial interval [a, b]
a, b = 0, 4  # Adjust based on the function
tolerance = 1e-6

try:
    root, updates = bisection_method(f, a, b, tol=tolerance)
    print(f"Root found: {root}")
    print(f"Updates: {updates}")
    
    # Plotting the root-finding process
    x_vals = np.linspace(a, b, 500)
    y_vals = f(x_vals)
    
    plt.figure(figsize=(10, 6))
    plt.plot(x_vals, y_vals, label='f(x)', color='blue')
    plt.axhline(0, color='black', linewidth=0.8, linestyle='--')
    plt.scatter(updates, f(updates), color='red', label='Bisection Updates')
    plt.title('Bisection Method Root Finding')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid()
    plt.show()
except ValueError as e:
    print(e)