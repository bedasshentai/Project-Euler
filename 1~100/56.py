from sympy import *
from itertools import *

ans = 0
for i in range(100):
    for j in range(100):
        x = pow(i, j)
        ans = max(ans, sum(list(map(int, list(str(x))))))
print(ans)