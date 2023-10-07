"""
File: regression.py
Last changed: 07/10/2023 17:34
Purpose:
Authors: Fernando Antonio Marques Schettini
Usage:
HowToExecute: python3 regression.py
"""


import matplotlib.pyplot as plt
import numpy as np

class Regression:
    # input data 'x' and 'y'
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.equation = None  # Stores the regression equation

    # Generate the coefficient matrix and independent vector for polynomial regression of a given 'order'
    def gen_coef(self, order):
        coef = []
        indep = []
        for j in range(order + 1):
            coef_row = []
            for i in range(j, j + order + 1):
                coef_row.append(sum([xi ** i for xi in self.get_x()]))
            coef.append(coef_row)
            indep.append(sum([(xi ** (j)) * yi for xi, yi in zip(self.get_x(), self.get_y())]))
        return coef, indep

    # Fit the data with a polynomial regression of a given 'order'
    def fit(self, order):
        coef, indep = self.gen_coef(order)
        eq_coef = np.linalg.solve(coef, indep)
        self.equation = np.poly1d(eq_coef[::-1])

    # Fit the data with an exponential regression
    def exp_fit(self):
        y_aux = self.get_y()
        self.set_y([np.log(y) for y in self.get_y()])
        coef, indep = self.gen_coef(1)
        eq_coef = np.linalg.solve(coef, indep)
        self.equation = lambda x: np.exp(eq_coef[1] * x + (eq_coef[0]))
        self.set_y(y_aux)

    # Predict the value for a given 'val' using the regression equation
    def predict(self, val):
        if self.equation is None:
            raise ValueError("You need to fit the model first")
        return self.equation(val)

    # Calculate the R-squared value of the regression model
    def rsquare(self):
        if self.equation is None:
            raise ValueError("You need to fit the model first")
        y_pred = self.equation(self.get_x())
        y_mean = np.mean(self.get_y())
        ssr = np.sum((y_pred - self.y) ** 2)
        sst = np.sum((self.y - y_mean) ** 2)
        r_squared = 1 - (ssr / sst)
        return r_squared

    # Calculate the Pearson correlation coefficient
    def pearson(self):
        if self.equation is None:
            raise ValueError("You need to fit the model first")
        # Calculate the mean of 'x' and 'y'
        mean_x = sum(self.get_x()) / len(self.get_x())
        mean_y = sum(self.get_y()) / len(self.get_y())
        # Calculate the necessary terms for Pearson correlation coefficient
        numerator = sum((x - mean_x) * (y - mean_y) for x, y in zip(self.get_x(), self.get_y()))
        denominator_x = sum((x - mean_x) ** 2 for x in self.get_x())
        denominator_y = sum((y - mean_y) ** 2 for y in self.get_y())
        # Calculate the Pearson correlation coefficient
        correlation = numerator / (denominator_x ** 0.5 * denominator_y ** 0.5)
        return correlation

    # Visualize the data and regression results
    def visualize(self):
        x_range = np.linspace(min(self.get_x()), max(self.get_x()), 100)
        y_fit = self.equation(x_range)
        plt.scatter(self.get_x(), self.get_y(), label="Data")
        plt.plot(x_range, y_fit, color='orange', label="Adjusted Equation")
        plt.title(f"Pearson: {self.pearson()}, R²: {self.rsquare()}, Equation: {self.get_equation()}")
        plt.legend()
        plt.xlabel("X")
        plt.ylabel("Y")
        plt.show()

    # Generate and display multiple regression visualizations
    def demo(self, num_graphs):
        for i in range(1, num_graphs + 1):
            self.fit(i)
            self.visualize()
        return

    # Getters and setters for 'x', 'y', and 'equation'
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
    # Example data
    x = np.array([1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990], dtype=np.int64)
    y = np.array([69, 76, 81, 90, 94, 100, 103, 108, 113, 115], dtype=np.int64)
    # Create an instance of the Regression class
    regression_model = Regression(x, y)
    # Fit the model with a polynomial of order 2
    regression_model.fit(2)
    # Visualize the results
    regression_model.visualize()
    # Generate and display multiple regression visualizations
    regression_model.demo(3)
    # Example data for exponential fit
    x = np.array([0, 1, 1.5, 2, 3, 5])
    y = np.array([1, 2, 2.5, 5, 8, 20])
    # Set new data and perform exponential fit
    regression_model.set_x(x)
    regression_model.set_y(y)
    regression_model.exp_fit()
    # Visualize the exponential regression results
    regression_model.visualize()
