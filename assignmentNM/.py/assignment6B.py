# function to calculate the divided difference table
def divided_diff_table(x, y, n):
    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i])

    return y

# function to perform Newton's Backward Interpolation
def newton_backward_interpolation(x, y, n, value):
    # calculate divided difference table
    div_diff_table = divided_diff_table(x, y, n)

    # initialize the result with the last term of the table
    result = div_diff_table[n - 1]

    # calculate the interpolation polynomial
    for i in range(n - 2, -1, -1):
        result = result * (value - x[i]) + div_diff_table[i]

    return result

# main function to take user input and perform interpolation
def main():
    # take user input for number of data points
    n = int(input("Enter the number of data points: "))

    # initialize x and y arrays
    x = []
    y = []

    # take user input for x and y values
    for i in range(n):
        x_val = float(input(f"Enter x[{i}]: "))
        y_val = float(input(f"Enter y[{i}]: "))
        x.append(x_val)
        y.append(y_val)

    # take user input for value to interpolate
    value = float(input("Enter the value to interpolate: "))

    # perform interpolation and print result
    result = newton_backward_interpolation(x, y, n, value)
    print(f"Interpolated value at {value}: {result}")

# call the main function
if __name__ == "__main__":
    main()
