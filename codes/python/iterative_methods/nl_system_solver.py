"""
File:           nl_system_solver.py
Last changed:   05/09/2023 11:18 
Purpose:        class with various methods to solve systems of NON linear equations.       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 nl_system_solver.py           
"""

import numpy as np
from system_solver import System_solver

class NL_system_solver:
    
    def __init__(self, func, jacob, flag=False):   
        self.func = func
        self.jacob = jacob
        self.flag = flag
        self.solver = None

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
        self.solver = System_solver(None, None, flag=self.flag)

        for iter in range(max_iter):
            self.solver.set_coef(self.jacob(x).tolist())
            self.solver.set_indep((-1*self.func(x)).tolist())

            guess = [0] * len(self.solver.get_coef())
            delta_x = self.solver.gauss_seidel(guess)
            x_new = x  + delta_x
            self.show_info(x_new, x, iter)

            # Checking stop criteria
            errors = [abs(x_new[i] - x[i]) for i in range(len(x))]
            if all(error < tol for error in errors):
                return x_new
            x = x_new
        return x_new
    
if __name__ == "__main__":
    
    def func(var):
        eq1 = var[0]**2 + var[1] - 5
        eq2 = var[0]**2 + var[1]**2 - 7
        return np.array([eq1, eq2])

    def jacob(var):
        jac = np.array([
            [2 * var[0], 1],
            [2 * var[0], 2 * var[1]]
        ])
        return jac

    solver = NL_system_solver(func, jacob) 
    initial_guess = [0.5, 1.5]
    solution = solver.newton_system(initial_guess)
    print("Solution:", solution)

