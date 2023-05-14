import numpy as np

# Read matrix A and vector b from user input
n = int(input("Enter the size of the matrix and vector: "))
A = np.zeros((n,n))
b = np.zeros(n)
for i in range(n):
    row = input(f"Enter the coefficients of row {i+1} of matrix A, separated by spaces: ")
    A[i,:] = np.array([float(x) for x in row.split()])
    b[i] = float(input(f"Enter the constant term for row {i+1} of vector b: "))

# Read maximum number of iterations and tolerance level from user input
max_iter = int(input("Enter the maximum number of iterations: "))
tolerance = float(input("Enter the tolerance level: "))

def gauss_seidel(A, b, x0, max_iter, tolerance):
    n = len(b)
    x = np.copy(x0)
    iterations = 0
    error = tolerance + 1
    
    # Iterate until convergence or maximum number of iterations
    while error > tolerance and iterations < max_iter:
        x_new = np.zeros(n)
        
        for i in range(n):
            s1 = np.dot(A[i,:i], x_new[:i])
            s2 = np.dot(A[i,i+1:], x[i+1:])
            x_new[i] = (b[i] - s1 - s2) / A[i,i]
        
        error = np.linalg.norm(x_new - x)
        x = np.copy(x_new)
        iterations += 1
        
        # Print intermediate results
        print("Step ", iterations, ":")
        print(x)
        print("Error: ", error)
        
    return x, iterations

# Call the Gauss-Seidel function and print the result
x0 = np.zeros(n)
x, iterations = gauss_seidel(A, b, x0, max_iter, tolerance)
print("Solution: ", x)
print("Iterations: ", iterations)

