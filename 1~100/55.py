from sympy import *
from itertools import *

cnt = 0
for i in range(1, 10000):
    x = i
    for j in range(50):
        x += int(str(x)[::-1])
        if str(x) == str(x)[::-1]:
            cnt += 1
            print(i, x)
            break
print(9999 - cnt)