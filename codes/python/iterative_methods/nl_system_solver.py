"""
File:           nl_system_solver.py
Last changed:   05/09/2023 11:18 
Purpose:        class with various methods to solve systems of NON linear equations.       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 nl_system_solver.py           
"""

import numpy as np

class NL_system_solver:
    
    def __init__(self, func, jacob, flag=False):   
        self.func = func
        self.jacob = jacob
        self.flag = flag

    def show_info(self, x_new, x, iter):
        if self.flag == True:
            print('###############################################')
            print(f'{iter + 1} Iteration:')
            for i in range(len(x_new)):
                abs_error = abs(x_new[i] - x[i])
                rel_error = abs_error / abs(x_new[i])
                print(f'Variable {i + 1}:')
                print(f'  ABS error: {abs_error}')
                print(f'  Relative error: {rel_error}')
            print(f'Variables: {x_new}')
            print('###############################################')
        
    def newton_system(self, x0, tol=1e-6, max_iter=100):
        x = np.array(x0, dtype=float)
        for iter in range(max_iter):
            F = self.func(x)
            J = self.jacob(x)
            delta_x = np.linalg.solve(J, -F)
            self.show_info(x + delta_x, x, iter)
            x += delta_x
            if np.linalg.norm(delta_x, np.inf) < tol:
                return x
        return x
    
if __name__ == "__main__":
    def func(x):
        return np.array([x[0]**2 + x[1]**2 - 1, x[0] + x[1] - 2])

    def jacob(x):
        return np.array([[2 * x[0], 2 * x[1]], [1, 1]])

    solver = NL_system_solver(func, jacob) 
    initial_guess = [0.5, 1.5]
    solution = solver.newton_system(initial_guess)
    print("Solution:", solution)

