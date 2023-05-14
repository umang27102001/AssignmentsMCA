def simpsons_rule(f, a, b, n):
    h = (b - a) / n
    sum_1 = 0
    sum_2 = 0

    for i in range(1, n):
        x_i = a + i*h
        if i % 2 == 0:
            sum_2 = sum_2 + f(x_i)
        else:
            sum_1 = sum_1 + f(x_i)

    integral = (h / 3) * (f(a) + 4*sum_1 + 2*sum_2 + f(b))
    return integral

# user input
f_string = input("Enter the integrand function: ")
f = lambda x: eval(f_string)
a = float(input("Enter the lower limit of integration: "))
b = float(input("Enter the upper limit of integration: "))
n = int(input("Enter the number of intervals: "))

# test
integral = simpsons_rule(f, a, b, n)
print(f"The approximate value of the integral is {integral}")
