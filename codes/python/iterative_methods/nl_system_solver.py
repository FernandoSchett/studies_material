"""
File:           nl_system_solver.py
Last changed:   05/09/2023 11:18 
Purpose:        class with various methods to solve systems of NON linear equations.       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 nl_system_solver.py           
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