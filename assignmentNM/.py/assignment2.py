# Assignment 2
# Subject: Numerical Methods
# Topic: Newton_Raphson implementation in python.
# Submitted By: UMANG KANCHAN (MCA sem-1).

from sympy import *
#  taking function input from user
inp=input("Enter an equation\n")
function=sympify(inp)

def f(n):    
    return float(function.subs('x',n))

Tol_Max=float(input("Enter the maximum tolerence\n"))        

# Newton_Raphson function definition
def Newton_Raphson(a):        
        x=symbols('x')       
        root=float(a)
        condition=True
        while condition:
            if float(diff(function,x).subs('x',a))==0:
                a=a+1      
            root=a-(f(a)/float(diff(function,x).subs('x',a)))
            condition=(abs(root-a)>=Tol_Max)
            a=root
        print(f"The root of given Equation is {round(root,6)}\n")      
def Find_Root():
    a=float(input("Enter initial value\n"));
    Newton_Raphson(a)
   
try:
    Find_Root()
except:
    print("No root possible for this initial value\n")    
