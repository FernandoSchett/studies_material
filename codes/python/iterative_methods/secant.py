"""
File:           secant.py
Last changed:   15/08/2023 10:59
Purpose:        find aprox. root using secants between 2 points.         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 secant.py           
"""

import math 

def sec_info(c,c_1,iter):
    abs_error = abs(c - c_1)
    rel_error = abs(c - c_1) / abs(c) 
    print('###############################################')
    print(f'{iter + 1} Iteration:')
    print(f'ABS error: {abs_error}')
    print(f'Relative error: {rel_error}')
    print(f'Root value: {c} f(c)= {f(c)}')
    print('###############################################')

def f(x):
    return x*math.log(x) - 1

def secant_method(x, x_1, tol=1e-6, max_iter=100):
    # bolzano, if f(a) . f(b) < 0, there's a root [a,b]
    if f(x) * f(x_1) >= 0:
        raise ValueError("There's no root in this interval.")
    
    iter_count = 0
    c = 0 
    
    while iter_count < max_iter:
        print(x, x_1)
        c_1 = c
        c = abs(((x*f(x_1)) - (x_1*f(x))) / (f(x_1)-f(x)) )
        sec_info(c, c_1, iter_count)

        if abs(f(c)) < tol or c == 0:
            return c
        
        if f(c) * f(x) < 0:
            x_1 = c
        else:
            x = c

        iter_count += 1
    
    return c

tolerance = 1e-6  
max_iterations = 100

root = secant_method(1, 2, tolerance, max_iterations)

if root is not None:
    print("Root found:", root)
