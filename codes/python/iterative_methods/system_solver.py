"""
File:           system_solver.py
Last changed:   05/09/2023 10:25 
Purpose:        class with various methods to solve systems of linear equations.       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 system_solver.py           
"""

import numpy as np

class System_solver:
    
    def __init__(self, coef, indep, jacob=False, flag=False):
        self.coef = coef
        self.indep = indep
        self.jacob = jacob
        self.flag = False

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

    def jacobi(self, x0, max_iter=100, tol=1e-6):
        n = len(self.coef)
        x = x0.copy()
        
        # Checking convergence
        for i in range(n):
            sigma = sum(abs(self.coef[i][j]) for j in range(n) if j != i)
            if self.coef[i][i] < abs(sigma):
                return None

        for iter in range(max_iter):
            x_new = x.copy()

            # Calculating
            for i in range(n):
                sigma = sum(self.coef[i][j] * x[j] for j in range(n) if j != i)
                x_new[i] = (self.indep[i] - sigma) / self.coef[i][i]
            
            # Checking stop criteria
            errors = [abs(x_new[i] - x[i]) for i in range(n)]
            if all(error < tol for error in errors):
                return x_new

            self.show_info(x_new, x, iter)
            x = x_new
        return x
    
    def gauss_seidel(self, x0, max_iter=100, tol=1e-6):
        n = len(self.coef)
        x = x0.copy()
        
        # Checking convergence
        for i in range(n):
            sigma = sum(abs(self.coef[i][j]) for j in range(n) if j != i)
            if self.coef[i][i] < abs(sigma):
                return None

        for iter in range(max_iter):
            x_new = x.copy()

            # Calculating
            for i in range(n):
                sigma_previous = sum(self.coef[i][j] * x_new[j] for j in range(i))
                sigma_next = sum(self.coef[i][j] * x[j] for j in range(i + 1, n))
                x_new[i] = (self.indep[i] - sigma_previous - sigma_next) / self.coef[i][i]
            
            # Checking stop criteria
            errors = [abs(x_new[i] - x[i]) for i in range(n)]
            if all(error < tol for error in errors):
                return x_new

            self.show_info(x_new, x, iter)
            x = x_new
        return x

if __name__ == "__main__":
    coef = [[10, -1, 2, 0],
            [-1, 11, -1, 3],
            [2, -1, 10, -1],
            [0, 3, -1, 8]]
    indep = [6, 25, -11, 15]
    
    system_solver = System_solver(coef, indep)
    
    x0 = [0, 0, 0, 0]  
    
    print("Solving using Jacobi method:")
    solution_jacobi = system_solver.jacobi(x0)
    print("Solution:", solution_jacobi)
    
    print("\nSolving using Gauss-Seidel method:")
    solution_gauss_seidel = system_solver.gauss_seidel(x0)
    print("Solution:", solution_gauss_seidel)