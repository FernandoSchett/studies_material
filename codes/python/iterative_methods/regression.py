"""
File:           regression.py
Last changed:   29/09/2023 29:02
Purpose:        class with various methods to predict values and tendencies         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 regression.py           
"""

import matplotlib.pyplot as plt
import numpy as np

class Regression:

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.equation = None

    def eq_adjust():

        return
    
    def gen_coef(self, order):
        coef = []
        indep = []
        for j in range(order + 1):
            coef_row = []
            for i in range(j, j + order + 1):
                coef_row.append(sum([xi ** i for xi in self.x]))
            coef.append(coef_row)
            indep.append(sum([(xi ** (j)) * yi for xi, yi in zip(self.x, self.y)]))
        return coef, indep

    def fit(self, order):
        coef, indep = self.gen_coef(order)
        eq_coef = np.linalg.solve(coef, indep) 
        self.equation = np.poly1d(eq_coef[::-1])

    def exp_fit(self):
        coef, indep = self.gen_coef(1)
        eq_coef = np.linalg.solve(coef, indep)
        self.equation = lambda x: np.exp(eq_coef[0])+np.exp(eq_coef[0]*x)

    def predict(self, val):
        if self.equation is None:
            raise ValueError("Você precisa ajustar o modelo primeiro")
        return self.equation(val)

    def rsquare(self):
        if self.equation is None:
            raise ValueError("Você precisa ajustar o modelo primeiro")

        y_pred = self.equation(self.x)
        y_mean = np.mean(self.y)

        ssr = np.sum((y_pred - self.y) ** 2)  
        sst = np.sum((self.y - y_mean) ** 2)

        r_squared = 1 - (ssr / sst)
        return r_squared

    def pearson(self):
        if self.equation is None:
            raise ValueError("Você precisa ajustar o modelo primeiro")

        # Calcular a média de x e y
        mean_x = sum(self.x) / len(self.x)
        mean_y = sum(self.y) / len(self.y)

        # Calcular os termos necessários para o coeficiente de correlação de Pearson
        numerator = sum((x - mean_x) * (y - mean_y) for x, y in zip(self.x, self.y))
        denominator_x = sum((x - mean_x) ** 2 for x in self.x)
        denominator_y = sum((y - mean_y) ** 2 for y in self.y)

        # Calcular o coeficiente de correlação de Pearson
        correlation = numerator / (denominator_x ** 0.5 * denominator_y ** 0.5)

        return correlation

    def visualize(self):
        x_range = np.linspace(min(self.x), max(self.x), 100)
        y_fit = self.equation(x_range)

        plt.scatter(self.x, self.y, label="Data")
        plt.plot(x_range, y_fit, color='orange', label="Adjusted Equation")
        plt.title(f"Pearson: {self.pearson()}, R²: {self.rsquare()}, Equation: {self.get_equation()}")
        plt.legend()
        plt.xlabel("X")
        plt.ylabel("Y")
        plt.show()

    def demo(self, num_graphs):
        for i in range(1, num_graphs + 1):
            self.fit(i)
            self.visualize()
        return

    def get_x(self):
        return self.x

    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y

    def set_y(self, y):
        self.y = y

    def get_equation(self):
        return self.equation

if __name__ == "__main__":
    x = np.array([1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990])
    y = np.array([69, 76, 81, 90, 94, 100, 103, 108, 113, 115])
    
    # Create an instance of the Regression class
    regression_model = Regression(x, y)
    
    # Fit the model with a polynomial of order 2
    regression_model.fit(1)
    
    # Visualize the results
    regression_model.visualize()
    regression_model.demo(3)

    x = np.array([1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990])
    y = np.array([69, 76, 81, 90, 94, 100, 103, 108, 113, 115])
    
    regression_model.set_x(x)
    regression_model.set_y(y)
    
    regression_model.exp_fit()
    regression_model.visualize()
