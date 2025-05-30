from sympy import *
from itertools import *

ans = 0
for i in range(101):
    for j in range(101):
        if binomial(i, j) > 1e6:
            ans += 1
print(ans)
