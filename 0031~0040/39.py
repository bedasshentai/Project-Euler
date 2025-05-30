from sympy import *

A = Matrix([[1, -2, 2],
            [2, -1, 2],
            [2, -2, 3]])
B = Matrix([[1, 2, 2],
            [2, 1, 2],
            [2, 2, 3]])
C = Matrix([[-1, 2, 2],
            [-2, 1, 2],
            [-2, 2, 3]])
O = Matrix([[3], [4], [5]])
triangles = [O]
cnt = [0 for _ in range(1001)]
for ori in triangles:
    for i in range(1, 1000):
        if sum(ori) * i > 1000: break
        cnt[sum(ori) * i] += 1
    if sum(A * ori) <= 1000: triangles.append(A * ori)
    if sum(B * ori) <= 1000: triangles.append(B * ori)
    if sum(C * ori) <= 1000: triangles.append(C * ori)
print(cnt.index(max(cnt)))