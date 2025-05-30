from sympy import *
import itertools

num = "1234567"
Num = itertools.permutations(num)
ans = 0
for i in Num:
    if isprime(int("".join(i))):
        ans = max(ans, int("".join(i)))
print(ans)
