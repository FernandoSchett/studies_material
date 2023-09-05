"""
File:           problem_5.py
Last changed:   05/09/2023 11:18 
Purpose:        problem 5 from Sistemas de Equações não Lineares.pptx (iterative computional methods)    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 problem_5.py     

Dependecies:
    numpy
    nl_system_solver.py
    math
"""

import numpy as np
from nl_system_solver import NL_system_solver
import math
def func(var):
    
    eq1 = 70*math.exp(var[0]) + 20*math.exp(var[1]) - 27.5702
    eq2 =  70*math.exp(var[0]*2) + 20*math.exp(var[1]*2) - 17.6567
    return np.array([eq1, eq2])

def jacob(var):
    jac = np.array([
            [70*math.exp(var[0]), 20*math.exp(var[1])],
            [140*math.exp(var[0]*2), 40*math.exp(var[1]*2)]
    ])
    return jac

solver = NL_system_solver(func, jacob, True) 
initial_guess = [-1.9, -0.015]
solution = solver.newton_system(initial_guess, max_iter=2)
print(f"Solution:", solution)