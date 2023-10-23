"""
File: interpol.py
Last changed: 23/10/2023 18:53
Purpose: class to predict values by interpolation
Authors: Fernando Antonio Marques Schettini
Usage:
HowToExecute: python3 interpol.py
"""

import matplotlib.pyplot as plt
import numpy as np

class Interpolate:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def lagrange(self, value):
        data = self.get_x()
        n = len(data)
        result = 0.0

        for i in range(n):
            term = self.get_y()[i]
            for j in range(n):
                if i != j:
                    term *= (value - data[j]) / (data[i] - data[j])
            result += term
        return result

    def newton(self, value):
        data = self.get_x()
        n = len(data)
        y = self.get_y()
        result = 0.0

        for i in range(n):
            term = y[i]
            for j in range(i):
                term *= (value - data[j])
            result += term
        return result

    # Getters and setters for 'x', 'y', and 'equation'
    def get_x(self):
        return self.x

    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y

    def set_y(self, y):
        self.y = y

if __name__ == "__main__":
    x_data = [1, 2, 3, 4]
    y_data = [2, 4, 8, 16]

    interpolator = Interpolate(x_data, y_data)

    # Lagrange
    lagrange_result = interpolator.lagrange(2.5)
    print(f"Lagrange interpolation at x=2.5: {lagrange_result}")

    # Newton
    newton_result = interpolator.newton(2.5)
    print(f"Newton interpolation at x=2.5: {newton_result}")
