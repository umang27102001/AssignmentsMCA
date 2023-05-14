import numpy as np

# Read matrix A and vector b from user input
n = int(input("Enter the size of the matrix: "))
A = np.zeros((n,n))
b = np.zeros(n)
for i in range(n):
    row = input(f"Enter the coefficients of row {i+1} of matrix A, separated by spaces: ")
    A[i,:] = np.array([float(x) for x in row.split()])
    b[i] = float(input(f"Enter the constant term for row {i+1} of vector b: "))

def gauss_elimination(A, b):
    n = len(b)
    
    # Forward elimination
    for k in range(n-1):
        for i in range(k+1, n):
            factor = A[i,k] / A[k,k]
            for j in range(k+1, n):
                A[i,j] -= factor * A[k,j]
            b[i] -= factor * b[k]
            
            # Print intermediate results
            print("Step ", k*n+i-k*(k+1)//2+1, ":")
            print(A)
            print(b)
    
    # Back substitution
    x = np.zeros(n)
    x[n-1] = b[n-1] / A[n-1,n-1]
    for i in range(n-2, -1, -1):
        sum = b[i]
        for j in range(i+1, n):
            sum -= A[i,j] * x[j]
        x[i] = sum / A[i,i]
    
    return x

# Call the Gauss Elimination function and print the result
x = gauss_elimination(A, b)
print("Solution: ", x)


