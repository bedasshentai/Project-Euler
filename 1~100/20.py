from sympy import *
n = factorial(100)
ans = 0
for i in str(n):
    ans += int(i)
print(ans)
