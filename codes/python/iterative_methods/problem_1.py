"""
File:           problem_1.py
Last changed:   05/09/2023 11:18 
Purpose:        problem 1 from Sistemas de Equações não Lineares.pptx (iterative computional methods)    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 problem_1.py     

Dependecies:
    numpy
    nl_system_solver.py
    math
"""

import numpy as np
import math
from nl_system_solver import NL_system_solver

def func(var, k):
    eq1 = 150 * math.cos(var[0]) + k*(var[1] - var[0]) - k*var[0] 
    eq2 = 50 * math.cos(var[1]) - k*(var[1] - var[0])
    return np.array([eq1, eq2])

def jacob(var, k):
    jac = np.array([
        [-1*150*math.sin(var[0]) - 2*k, k],
        [k, -1*50*math.sin(var[1]) - k]
    ])
    return jac

k_values = [10, 100, 500, 1000]
for k in k_values:
    func_k = lambda var: func(var, k)
    jacob2_k = lambda var: jacob(var, k)

    solver = NL_system_solver(func_k, jacob2_k, False) 
    initial_guess = [0.5, 1.5]
    solution = solver.newton_system(initial_guess)
    print(f"Solution when k = {k}:", solution)