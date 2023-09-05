"""
File:           root_finder.py
Last changed:   04/09/2023 22:40
Purpose:        class with various methods to find aprox. root         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 root_finder.py           
"""

import math 

class Rootfinder:

    def __init__(self, f, df, flag=False):
        self.f = f
        self.df = df
        self.flag = False

    def info(self, c, c_1, iter):
        if self.flag == True:
            abs_error = abs(c - c_1)
            rel_error = abs(c - c_1) / abs(c) 
            print('###############################################')
            print(f'{iter + 1} Iteration:')
            print(f'ABS error: {abs_error}')
            print(f'Relative error: {rel_error}')
            print(f'Root value: {c} f(c)= {self.f(c)}')
            print('###############################################')

    def bissection(self, a, b, tol=1e-6, max_iter=100):
        # bolzano, if f(a) . f(b) < 0, there's a root [a,b]
        if self.f(a) * self.f(b) >= 0:
            raise ValueError("There's no root in this interval.")
        
        if self.flag == True:
            print('Minimun iteration to b - a < tol: ', math.ceil(math.log(abs(b - a)/tol)/math.log(2)) )
        iter = 0
        c = 0
        while (b - a) > tol and iter < max_iter:
            c_1 = c
            c = (a + b) / 2
            self.info(c,c_1,iter)

            if self.f(c) == 0:
                return c
            elif self.f(c) * self.f(a) < 0:
                b = c
            else:
                a = c
            iter += 1

        return c
    
    def secant_method(self, x, x_1, tol=1e-6, max_iter=100):
        # bolzano, if f(a) . f(b) < 0, there's a root [a,b]
        if self.f(x) * self.f(x_1) >= 0:
            raise ValueError("There's no root in this interval.")
        
        iter_count = 0
        c = 0 
        
        while iter_count < max_iter:
            c_1 = c
            c = abs(((x*f(x_1)) - (x_1*f(x))) / (f(x_1)-f(x)) )
            self.info(c, c_1, iter_count)

            if abs(self.f(c)) < tol or c == 0:
                return c
            
            if self.f(c) * self.f(x) < 0:
                x_1 = c
            else:
                x = c

            iter_count += 1
        
        return c
    
    def newton_raphson(self, x, tol=1e-6, max_iter=100):
        if abs(self.f(x)) < tol:
                return x
        for i in range(max_iter):
            if self.df(x) == 0:
                raise ValueError(f"Derivative is 0 at {x}.")
            x_1 = x - self.f(x) / self.df(x)
            self.nf_info(x, x_1, i)
            if abs(self.f(x)) < tol:
                return x
            x = x_1
        return x
    

if __name__ == "__main__":

    def f(x):
        return x**3 - 2*x**2 + 4*x - 8

    def df(x):
        return 3*x**2 - 4*x + 4

    root_finder = Rootfinder(f, df)

    a = 1
    b = 3
    tol = 1e-6
    max_iter = 100

    print("Bisection Method:")
    root_bisection = root_finder.bissection(a, b, tol, max_iter)
    print(f"Root found: {root_bisection}\n")

    x = 1.5
    x_1 = 2.5

    print("Secant Method:")
    root_secant = root_finder.secant_method(x, x_1, tol, max_iter)
    print(f"Root found: {root_secant}\n")

    initial_guess = 2.0

    print("Newton-Raphson Method:")
    root_newton = root_finder.newton_raphson(initial_guess, tol, max_iter)
    print(f"Root found: {root_newton}")

