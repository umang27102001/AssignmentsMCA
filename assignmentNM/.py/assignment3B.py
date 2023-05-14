import numpy as np

# Read matrix A and vector b from user input
n = int(input("Enter the size of the matrix and vector: "))
A = np.zeros((n,n))
b = np.zeros(n)
for i in range(n):
    row = input(f"Enter the coefficients of row {i+1} of matrix A, separated by spaces: ")
    A[i,:] = np.array([float(x) for x in row.split()])
    b[i] = float(input(f"Enter the constant term for row {i+1} of vector b: "))

def gauss_jordan(A, b):
    n = len(b)
    
    # Forward elimination
    for k in range(n):
        pivot = A[k,k]
        for j in range(k, n):
            A[k,j] /= pivot
        b[k] /= pivot
        for i in range(n):
            if i != k:
                factor = A[i,k]
                for j in range(k, n):
                    A[i,j] -= factor * A[k,j]
                b[i] -= factor * b[k]
        
        # Print intermediate results
        print("Step ", k+1, ":")
        print(A)
        print(b)
    
    return b

# Call the Gauss-Jordan function and print the result
x = gauss_jordan(A, b)
print("Solution: ", x)
