from sympy import *
B = Matrix([1, 1]) # column vector
K = Matrix([3, 2])
X = Matrix([[3, 4], [2, 3]])

while (B[0] + 1) // 2 < 1e12:
    B = X * B
    print((B[0] + 1) // 2, (B[1] + 1) // 2)