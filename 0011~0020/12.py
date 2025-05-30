from sympy import *
ans = 0
for i in range(1, 100000):
    ans += i
    factors = divisors(ans)
    if len(factors) > 500:
        print(ans)
        break