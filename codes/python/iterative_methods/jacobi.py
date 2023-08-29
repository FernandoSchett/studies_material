"""
File:           jacobi.py
Last changed:   29/08/2023 10:40
Purpose:        find aprox. solution in linear systems with diagonally dominant matrices.         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   python3 jacobi.py           
"""

def jac_info(x_new, x, iter):
    print('###############################################')
    print(f'{iter + 1} Iteration:')
    for i in range(len(x_new)):
        abs_error = abs(x_new[i] - x[i])
        rel_error = abs_error / abs(x_new[i])
        print(f'Variable {i + 1}:')
        print(f'  ABS error: {abs_error}')
        print(f'  Relative error: {rel_error}')
    print(f'Variables: {x_new}')
    print('###############################################')


def jacobi(A, b, x0, max_iter=100, tol=1e-6):
    n = len(A)
    x = x0.copy()
    
    # Checking convergence
    for i in range(n):
        sigma = sum(abs(A[i][j]) for j in range(n) if j != i)
        if A[i][i] < abs(sigma):
          return None

    for iter in range(max_iter):
        x_new = x.copy()

        # Calculating
        for i in range(n):
            sigma = sum(A[i][j] * x[j] for j in range(n) if j != i)
            x_new[i] = (b[i] - sigma) / A[i][i]
        
        # Checking stop criteria
        errors = [abs(x_new[i] - x[i]) for i in range(n)]
        if all(error < tol for error in errors):
            return x_new

        jac_info(x_new, x, iter)
        x = x_new
    return x

# Coefficients
A = [[4, -1, 0],
     [-1, 4, -1],
     [0, -1, 4]]

# Idepent Variables
b = [5, 5, 10]

x0 = [0, 0, 0]

solution = jacobi(A, b, x0, 100, 1e-6)

if solution != None:
  print("Solution found:", solution)
else:
  print("Error: The system does not have a diagonally dominant matrix.")
