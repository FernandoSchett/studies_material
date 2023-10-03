"""
File:           regression.py
Last changed:   29/09/2023 29:02
Purpose:        class with various methods to predict values and tendencies         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 regression.py           
"""

import matplotlib.pyplot as plt
from system_solver import System_solver
import numpy as np

class Regression:

    def __init__(self, x, y, flag=False):
        self.x = x
        self.y = y
        self.flag = flag 
    
    def set_data(self, x, y):
        self.x = x
        self.y = y
    
    def get_data(self):
        return self.x, self.y
    
    def gen_coef(self, order):
        x = self.x
        y = self.y
        
        coef = []
        indep = []
        for i in range(order + 1):
            coef.append([ sum([xi ** i for xi in x]), 
                          sum([xi ** i + 1 for xi in x]), 
                          sum([xi ** order + i for xi in x])
                        ])
            indep.append(sum([(xi ** (i)) * yi for xi, yi in zip(x, y)]))
        return coef, indep

    def gen_equation(self, order):
        coef, indep = self.gen_coef(self, order)
        system_solver = System_solver(coef, indep)        
        eq_coef = system_solver.gauss_seidel([0, 0, 0, 0])
        equation = np.poly1d(eq_coef)
        return equation
    
    
