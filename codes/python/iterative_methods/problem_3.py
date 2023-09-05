"""
File:           problem_3.py
Last changed:   05/09/2023 11:18 
Purpose:        problem 3 from Sistemas de Equações não Lineares.pptx (iterative computional methods)    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 problem_3.py     

Dependecies:
    numpy
    nl_system_solver.py
    math
"""

import numpy as np
from nl_system_solver import NL_system_solver

def func(var):
    eq1 = (var[0]**4 + 0.06823*var[0]) - (var[1]**4 + 0.05848*var[1]) - 0.01509
    eq2 = (var[0]**4 + 0.05848*var[0]) - (2*(var[1]**4)+ 0.11696*var[1]) 
    return np.array([eq1, eq2])

def jacob(var):
    jac = np.array([
        [4*(var[0]**3) + 0.06823, -4*(var[1]**3) - 0.05848],
        [4*(var[0]**3) + 0.05848, -8*(var[1]**3) - 0.11696]
    ])
    return jac


solver = NL_system_solver(func, jacob, True) 
initial_guess = [0.3, 0.3]
solution = solver.newton_system(initial_guess)
print(f"Solution:", solution)