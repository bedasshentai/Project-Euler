from sympy import *
from itertools import *
from fractions import *

inv2 = Fraction(1, 2)
lis = [inv2]
for i in range(1000):
    lis.append(Fraction(1, 2 + lis[-1]))

ans = 0
for f in lis:
    f += 1
    if len(str(f.numerator)) > len(str(f.denominator)):
        ans += 1
print(ans)