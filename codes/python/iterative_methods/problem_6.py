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
import math
def func(var):
    
    eq1 = 16*var[0] - math.cos(var[1] - 2*var[0])
    eq2 =  16*var[1] + 0.75*math.sin(-var[1]-3*var[0])
    return np.array([eq1, eq2])

def jacob(var):
    jac = np.array([
            [16 - 2*math.sin(var[1] - 2*var[0]), math.sin(var[1] - 2*var[0])],
            [-3*0.75*math.cos(-var[1] - 3*var[0]), 16 - 0.75*math.cos(-var[1] - 3*var[0])]
    ])
    return jac

solver = NL_system_solver(func, jacob, True) 
initial_guess = [0.1,0.01]
solution = solver.newton_system(initial_guess, max_iter=1)
print(f"Solution:", solution)