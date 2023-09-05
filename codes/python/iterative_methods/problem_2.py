"""
File:           problem_2.py
Last changed:   05/09/2023 11:18 
Purpose:        problem 2 from Sistemas de Equações não Lineares.pptx (iterative computional methods)    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 problem_2.py     

Dependecies:
    numpy
    nl_system_solver.py
    math
"""

import numpy as np
import math
from nl_system_solver import NL_system_solver

def func(var, k):
    eq1 = 25 * math.cos(var[0]) + k*(var[1] - var[0]) - k*var[0] 
    eq2 = 15 * math.cos(var[1]) + k*(var[2] - var[1]) - k*(var[1] - var[0])
    eq3 = 5 * math.cos(var[2]) - k*(var[2] - var[1])
    return np.array([eq1, eq2, eq3])

def jacob(var, k):
    jac = np.array([
        [-1*25*math.sin(var[0]) - 2*k, k, 0],
        [k, -1*15*math.sin(var[1]) - 2*k, k],
        [0, -k, -1*5*math.sin(var[2]) - k]
    ])
    return jac

k_values = [10, 100, 1000]
for k in k_values:
    func_k = lambda var: func(var, k)
    jacob2_k = lambda var: jacob(var, k)

    solver = NL_system_solver(func_k, jacob2_k, False) 
    initial_guess = [0.5, 1.5, 2]
    solution = solver.newton_system(initial_guess)
    print(f"Solution when k = {k}:", solution)