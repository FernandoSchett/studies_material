


import numpy as np
from tabulate import tabulate
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def system_equations(x, y, z):
    eq1 = x**2 + y**2 + z**2 - 9
    eq2 = x * y * z - 1
    eq3 = x + y - z**2
    return np.array([eq1, eq2, eq3])

def jacobian_matrix(x, y, z):
    jac = np.array([
        [2*x, 2*y, 2*z],
        [y*z, x*z, x*y],
        [1, 1, -2*z]
    ])
    return jac

def newton_raphson_system(equations, jacobian, initial_guess, tolerance):
    x_n = np.array(initial_guess)
    iter_count = 0
    
    table = []
    header = ["Iteration", "x", "y", "z", "Abs. Error", "Rel. Error"]
    
    while True:
        f_xn = equations(*x_n)
        jacobian_xn = jacobian(*x_n)
        
        delta_x = np.linalg.solve(jacobian_xn, -f_xn)
        x_n1 = x_n + delta_x
        
        abs_error = np.linalg.norm(x_n1 - x_n, np.inf)
        rel_error = abs_error / (np.linalg.norm(x_n1, np.inf) + 1e-10)
        
        table.append([iter_count, x_n[0], x_n[1], x_n[2], abs_error, rel_error])
        
        x_n = x_n1
        iter_count += 1
        
        if abs_error < tolerance:
            table.append([iter_count, x_n[0], x_n[1], x_n[2], abs_error, rel_error])
            break
    
    print(tabulate(table, headers=header, tablefmt="grid"))
    
    return x_n

initial_guess = [0.7, 1.5, 1.5]
tolerance = 0.001

root = newton_raphson_system(system_equations, jacobian_matrix, initial_guess, tolerance)

# Plotting the roots
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(root[0], root[1], root[2], color='red', label='Root')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Root Found')
plt.legend()
plt.show()