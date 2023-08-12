"""
File:           bisection.py
Last changed:   10/08/2023 10:33
Purpose:        find aprox. root in a interval [a,b]         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 bisection.py           
"""

import math 

def f(x):
    return x*math.log(x) - 1

def bis_info(c,c_1,iter):
    abs_error = abs(c - c_1)
    rel_error = abs(c - c_1) / abs(c) 
    print('###############################################')
    print(f'{iter + 1} Iteration:')
    print(f'ABS error: {abs_error}')
    print(f'Relative error: {rel_error}')
    print(f'Root value: {c} f(c)= {f(c)}')
    print('###############################################')
    
def bissection(a, b, tol=1e-6, max_iter=100):
    # bolzano, if f(a) . f(b) < 0, there's a root [a,b]
    if f(a) * f(b) >= 0:
        raise ValueError("There's no root in this interval.")
    
    print('Minimun iteration to b - a < tol: ', math.ceil(math.log(abs(b - a)/tol)/math.log(2)) )
    iter = 0
    c = 0
    while (b - a) > tol and iter < max_iter:
        c_1 = c
        c = (a + b) / 2
        bis_info(c,c_1,iter)

        if f(c) == 0:
            return c
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
        iter += 1

    return c


# Example
tolerance = 1e-5
max_iterations = 1000

root = bissection(1, 2, tolerance, max_iterations)
print("Root found:", root)
