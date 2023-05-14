def divided_diff(x, y):
    n = len(x)
    coefficients = []
    for i in range(n):
        coefficients.append(y[i])

    for j in range(1, n):
        for i in range(n-1, j-1, -1):
            coefficients[i] = (coefficients[i] - coefficients[i-1]) / (x[i] - x[i-j])

    return coefficients

def newton_interpolation(x, y, xi):
    coefficients = divided_diff(x, y)
    n = len(x)
    result = coefficients[n-1]
    for i in range(n-2, -1, -1):
        result = result * (xi - x[i]) + coefficients[i]
    return result

# user input
n = int(input("Enter the number of data points: "))
x = []
y = []
for i in range(n):
    x_i = float(input(f"Enter x{i+1}: "))
    y_i = float(input(f"Enter y{i+1}: "))
    x.append(x_i)
    y.append(y_i)

# test
xi = float(input("Enter the value of xi for interpolation: "))
yi = newton_interpolation(x, y, xi)
print(f"Interpolated value at xi = {xi} is {yi}")
