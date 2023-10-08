from regression import Regression
import numpy as np

if __name__ == "__main__":
    
    # Primeira atividade:
    x = np.array([0.8, 1.5, 2, 5], dtype=np.float64)
    y = np.array([2.5, 0.4, 0.25, 3.23], dtype=np.float64)

    regression_model = Regression(x, y)
    regression_model.fit(2)
    regression_model.visualize()
    
    
    # Segunda atividade:
    x = np.array([1800, 1850, 1900, 1950, 2000], dtype=np.float64)
    y = np.array([5e+09, 1e+10, 1.5e+10, 2e+10, 2.5e+10], dtype=np.float64)
    
    regression_model.set_x(x)
    regression_model.set_y(y)
    regression_model.exp_fit()

    # Visualize the exponential regression results
    regression_model.visualize()
    print(regression_model.predict(2010))

    # Terceira atividade:
    x = np.array([1950, 1960, 1970, 1980, 2000], dtype=np.float64)
    y = np.array([105, 80.2, 61.7, 48.8, 28.3], dtype=np.float64)
    
    regression_model.set_x(x)
    regression_model.set_y(y)
    regression_model.exp_fit()
    regression_model.visualize()
    print(regression_model.predict(2020))


    # Quarta Atividade atividade:
    x = np.array([1950, 1960, 1970, 1980, 1990, 2000], dtype=np.float64)
    y = np.array([43.5, 44, 37.7, 31.87, 23.72, 21.06], dtype=np.float64)
    
    regression_model.set_x(x)
    regression_model.set_y(y)
    regression_model.demo(3)

    # Quinta atividade:
    x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13], dtype=np.float64)

    y = np.array([
    263.15,
    277.77,
    294.11,
    312.5,
    333.33,
    344.82,
    370.37,
    400.0,
    416.66,
    454.54,
    476.19,
    500.0,
    526.31
    ], dtype=np.float64)

    regression_model.set_x(x)
    regression_model.set_y(y)
    regression_model.exp_fit()
    regression_model.visualize()
