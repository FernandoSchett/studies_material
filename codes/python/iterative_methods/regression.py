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

    def __init__(self, x, y, flag=False):
        self.x = x
        self.y = y
        self.equation = None
        self.flag = flag 
    
    def gen_coef(self, order):
        x = self.x
        y = self.y
        
        coef = []
        indep = []
        for j in range(order + 1):
            coef_row = []
            for i in range(j, j + order + 1):
                coef_row.append(sum([xi ** i for xi in x]))
            coef.append(coef_row)
            indep.append(sum([(xi ** (j)) * yi for xi, yi in zip(x, y)]))
        return coef, indep

    def fit(self, order):
        coef, indep = self.gen_coef(order)
        eq_coef = np.linalg.solve(coef, indep)     
        self.equation = np.poly1d(eq_coef[::-1])
    
    def predict(self, val):
        return self.equation(val)
    
    def rsquare(self):
        if self.equation is None:
            raise ValueError("You need to fit the model first")

        y_pred = self.equation(self.x)
        y_mean = np.mean(self.y)

        ssr = np.sum((y_pred - self.y) ** 2)  
        sst = np.sum((self.y - y_mean) ** 2)

        r_squared = 1 - (ssr / sst)
        return r_squared

    def pearson(self):
        if self.equation is None:
            raise ValueError("You need to fit the model first")

        y_pred = self.equation(self.x)
        corr_matrix = np.corrcoef(self.y, y_pred)
        correlation = corr_matrix[0, 1]

        return correlation
    
    def visualize(self):
        plt.scatter(self.get_x(), self.get_y(), label="Data")
        plt.plot(x_range, y_fit, color='orange', label="Fitted Equation")
        plt.title(f"Pearson:{self.pearson()}, R²:{self.rsquared()}, Equation: {self.get_equation()}")
        plt.legend()
        plt.xlabel("X")
        plt.ylabel("Y")
        plt.show()
    
    def demo(self, num_graphs):
        for i in range(num_graphs):

        return
        # Método de Get para o atributo 'x'
    def get_x(self):
        return self.x

    # Método de Set para o atributo 'x'
    def set_x(self, novo_x):
        self.x = novo_x

    # Método de Get para o atributo 'y'
    def get_y(self):
        return self.y

    # Método de Set para o atributo 'y'
    def set_y(self, novo_y):
        self.y = novo_y

    # Método de Get para o atributo 'flag'
    def get_flag(self):
        return self.flag

    # Método de Set para o atributo 'flag'
    def set_flag(self, nova_flag):
        self.flag = nova_flag

    # Método de Get para o atributo 'equation'
    def get_equation(self):
        return self.equation

    # Método de Set para o atributo 'equation'
    def set_equation(self, nova_equation):
        self.equation = 

if __name__ == "__main__":
    # Sample data for demonstration
    x = np.array([1, 2, 3, 4, 5])
    y = np.array([2, 4, 5, 4, 5])

    # Create an instance of the Regression class
    regression_model = Regression(x, y)

    # Fit the model with a specified order
    order = 1
    regression_model.fit(order)
    print(regression_model.equation)
    # Predict a value
    prediction = regression_model.predict(6)
    print(f"Prediction for x=6: {prediction}")

    # Calculate R-squared and Pearson correlation
    r_squared = regression_model.rsquare()
    correlation = regression_model.pearson()

    print(f"R-squared: {r_squared}")
    print(f"Pearson correlation: {correlation}")

    # Plot the data and the fitted equation
    x_range = np.linspace(min(x), max(x), 100)
    y_fit = regression_model.equation(x_range)

    plt.scatter(x, y, label="Data")
    plt.plot(x_range, y_fit, color='red', label="Fitted Equation")
    plt.legend()
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.show()
