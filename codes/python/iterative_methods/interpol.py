"""
File:           interpol.py
Last changed:   05/09/2023 19:49 
Purpose:        class with various methods to interpolate dots.       
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 interpol.py     
Dependecies:
    numpy
    matplotib
"""

import matplotlib.pyplot as plt
import numpy as np

class Interpolate:

    def __init__(self, x, y, equation=None, flag=False):
        self.x = x
        self.y = y
        self.equation = equation
        self.flag = flag

    def lagrange_fit(self):
        data = self.get_x()
        n = len(data)
        poly = [0.0] * (n)

        for i in range(n):
            term = self.get_y()[i]
            for j in range(n):
                if i != j:
                    term *= np.poly1d([1, -data[j]]) / (data[i] - data[j])
            poly += term
        self.equation = poly
        self.get_info()

    def newton_fit(self):
        data = self.get_x()
        n = len(data)
        y = self.get_y()
        diff_table = np.zeros((n, n), dtype=float)

        for i in range(n):
            diff_table[i][0] = y[i]

        for j in range(1, n):
            for i in range(n - j):
                diff_table[i][j] = (diff_table[i + 1][j - 1] - diff_table[i][j - 1]) / (data[i + j] - data[i])

        poly = np.poly1d(diff_table[0, 0])
        for j in range(1, n):
            factors = np.poly1d([1])
            for i in range(j):
                factors *= np.poly1d([1, -data[i]])
            poly += diff_table[0, j] * factors

        self.equation = poly
        self.get_info()
    
    def gregory_newton_fit(self):
        data = self.get_x()
        n = len(data)
        y = self.get_y()
        diff_table = np.zeros((n, n), dtype=float)

        for i in range(n):
            diff_table[i][0] = y[i]

        for j in range(1, n):
            for i in range(n - j):
                diff_table[i][j] = (diff_table[i + 1][j - 1] - diff_table[i][j - 1]) / (data[i + j] - data[i])

        poly = np.poly1d(diff_table[0, 0])
        for j in range(1, n):
            factors = np.poly1d([1])
            for i in range(j):
                factors *= np.poly1d([1, -data[i]])
            poly += diff_table[0, j] * factors

        self.equation = poly
        self.get_info()

    def predict(self, value):
        return self.equation(value)
    
    def get_info(self):
        if self.flag == True:
            print("================")
            print(f"Equation:{self.equation}")
            print("================")

    def visualize(self):
        x_range = np.linspace(min(self.get_x()), max(self.get_x()), 100)
        y_fit = self.equation(x_range)
        plt.scatter(self.get_x(), self.get_y(), label="Data")
        plt.plot(x_range, y_fit, color='orange', label="Adjusted Equation")
        plt.title(f"Equation: {self.equation}")
        plt.legend()
        plt.xlabel("X")
        plt.ylabel("Y")
        plt.show()
    
    # Getters and setters for 'x', 'y'
    def get_x(self):
        return self.x

    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y

    def set_y(self, y):
        self.y = y

if __name__ == "__main__":
    
    x_data = [0, 10, 20]
    y_data = [0, 6, 4]
    value = 5

    interpolator = Interpolate(x_data, y_data, flag=True)

    interpolator.lagrange_fit()
    print("Lagrange interpolation:", interpolator.predict(value))
    interpolator.visualize()

    interpolator.newton_fit()
    print("Newton interpolation:", interpolator.predict(value))
    interpolator.visualize()

    interpolator.gregory_newton_fit()
    print("Gregory-Newton interpolation:", interpolator.predict(value))
    interpolator.visualize()