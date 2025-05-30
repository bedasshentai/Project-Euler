from sympy import *

Str = ""
ans = 1
d = 1
num = 1
while d <= 1000000:
    if len(Str) < d:
        Str += str(num)
        num += 1
    if d == 1 or d == 10 or d == 100 or d == 1000 or d == 10000 or d == 100000:
        ans *= int(Str[d - 1])
    d += 1

print(ans)