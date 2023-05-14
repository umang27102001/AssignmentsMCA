import numpy as np

# Function to calculate Lagrange basis polynomial
def lagrange_basis(x, i, x_values):
    basis = 1
    for j in range(len(x_values)):
        if i != j:
            basis *= (x - x_values[j]) / (x_values[i] - x_values[j])
    return basis

# Function to perform Lagrange interpolation
def lagrange_interpolation(x, x_values, y_values):
    n = len(x_values)
    lagrange_poly = 0
    for i in range(n):
        lagrange_poly += y_values[i] * lagrange_basis(x, i, x_values)
    return lagrange_poly

# Get input from user
n = int(input("Enter number of data points: "))
x_values = np.zeros(n)
y_values = np.zeros(n)
print("Enter data points:")
for i in range(n):
    x_values[i] = float(input("x[" + str(i) + "] = "))
    y_values[i] = float(input("y[" + str(i) + "] = "))
x = float(input("Enter interpolation point: "))

# Perform Lagrange interpolation
y = lagrange_interpolation(x, x_values, y_values)

# Print solution
print("Interpolated value at x = " + str(x) + " is y = " + str(y))

