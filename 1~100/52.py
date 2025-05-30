from sympy import *
from itertools import *

for i in range(1, 142858):
    lis = set([''.join(map(str, set(str(i * x)))) for x in range(1, 7)])
    if len(lis) == 1:
        print(i)