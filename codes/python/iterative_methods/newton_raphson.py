"""
File:           newton_raphson.py
Last changed:   11/08/2023 18:10
Purpose:        find aprox. root using function derivative.         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 newton_raphson.py           
"""

import math 

def nf_info(c,c_1,iter):
    abs_error = abs(c - c_1)
    rel_error = abs(c - c_1) / abs(c) 
    print('###############################################')
    print(f'{iter + 1} Iteration:')
    print(f'ABS error: {abs_error}')
    print(f'Relative error: {rel_error}')
    print(f'Derivative value: {df(c)}')
    print(f'Root value: {c} f(c)= {f(c)}')
    print('###############################################')

def f(x):
    return x*math.log(x) - 1

def df(x):
    return math.log(x) + 1
    
def newton_raphson(x, tol=1e-6, max_iter=100):
    if abs(f(x)) < tol:
            return x
    for i in range(max_iter):
        if df(x) == 0:
            raise ValueError(f"Derivative is 0 at {x}.")
        x_1 = x - f(x) / df(x)
        nf_info(x, x_1, i)
        if abs(f(x)) < tol:
            return x
        x = x_1
    return x

# Example
x0 = 1 
tolerance = 1e-2
max_iterations = 100

root = newton_raphson(x0, tolerance, max_iterations)
print("Root found:", root)