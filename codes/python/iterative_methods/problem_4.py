"""
File:           problem_4.py
Last changed:   05/09/2023 11:18 
Purpose:        problem 4 from Sistemas de Equações não Lineares.pptx (iterative computional methods)    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 problem_4.py     

Dependecies:
    numpy
    nl_system_solver.py
    math
"""

import numpy as np
from nl_system_solver import NL_system_solver

def func(var):
    
    eq1 = var[0]**2 + var[1]**2 - 15
    eq2 =  1/(var[0]**2) + var[1]**2 - var[2]
    eq3 = var[0] + var[1] + var[2] - 500
    return np.array([eq1, eq2, eq3])

def jacob(var):
    jac = np.array([
            [2*var[0], 2*var[1], -1],
            [-2*(var[0]**-3), 2*var[1], -1],
            [1, 1, 1]
    ])
    return jac

solver = NL_system_solver(func, jacob, True) 
initial_guess = [20, 20, 400]
solution = solver.newton_system(initial_guess, max_iter=2)
print(f"Solution:", solution)