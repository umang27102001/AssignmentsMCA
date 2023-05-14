def trapezium_rule(f, a, b, n):
    h = (b - a) / n
    sum = 0.5 * (f(a) + f(b))

    for i in range(1, n):
        x_i = a + i*h
        sum = sum + f(x_i)

    integral = h * sum
    return integral

# user input
f_string = input("Enter the integrand function: ")
f = lambda x: eval(f_string)
a = float(input("Enter the lower limit of integration: "))
b = float(input("Enter the upper limit of integration: "))
n = int(input("Enter the number of intervals: "))

# test
integral = trapezium_rule(f, a, b, n)
print(f"The approximate value of the integral is {integral}")
