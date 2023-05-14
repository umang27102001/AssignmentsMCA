# Assignment 1
# Subject: Numerical Methods
# Topic: Regula Falsi implementation using python.
# Submitted By: UMANG KANCHAN (MCA sem-1).

#************************************Program starts*********************************

#  importing sympy
from sympy import *

# taking function input from user

inp=input("Enter an equation:\n")
function=sympify(inp)
def f(n):    
    return float(function.subs('x',n))

# taking maximum tolerance from user

Tol_Max=float(input("\nEnter the maximum tolerance\n")) 

# Regula falsi function
def regulaFalsi(a,b):
    s=a
    e=b        
    if f(b)==f(a):
        a=a+1 
        s=a
    print(f"Interval Found {s,e}:\n")   
    root=(a*f(b)-b*f(a))/float((f(b)-f(a)))
    temp=root
    condition=True
    while condition:        
        if f(root)==0:
            break
        elif f(root)*f(b)<0:
            a=root
        else:
            b=root
        # print(f"The intermediate root of {inp} in the interval {s,e} is {round(root,6)}")    
        root=(a*f(b)-b*f(a))/float((f(b)-f(a)))        
        condition = (abs(temp-root)>=Tol_Max)
        temp=root 
    print(f"The root of {inp} in the interval {s,e} is {round(root,6)}.\n")  

# function for finding the interval.
def rangeN():
    a=0
    b=0
    i=-10    
    isTrue=False    
    while(i<10):   
        if("log" in inp and i<=0):
            i=i+1
            continue
        if(f(i)*f(i+1)<0):
            a=i
            b=i+1
            isTrue=True
            regulaFalsi(a,b)         
        elif(f(i)==0):
            isTrue=True
            print(f"The root of equation in {i,i+1} is",i)                   
        i=i+1
    if(not isTrue):
            print("No interval found such that f(a)*f(b)<0\n")      
def findRoot():
        rangeN()

findRoot()

#************************************Program ends****************************************
