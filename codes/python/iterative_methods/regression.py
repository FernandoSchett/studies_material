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

        y_pred = self.equation(self.x)
        corr_matrix = np.corrcoef(self.y, y_pred)
        correlation = corr_matrix[0, 1]

        return correlation

    def visualize(self):
        x_range = np.linspace(min(self.x), max(self.x), 100)
        y_fit = self.equation(x_range)

        plt.scatter(self.x, self.y, label="Dados")
        plt.plot(x_range, y_fit, color='orange', label="Equação Ajustada")
        plt.title(f"Pearson: {self.pearson()}, R²: {self.rsquare()}, Equação: {self.get_equation()}")
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
    regression_model.fit(2)
    
    # Visualize the results
    regression_model.visualize()
    regression_model.demo(3)