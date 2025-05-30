from sympy import *
ans = 0
p = prime(1)
while p < 2e6:
    ans += p
    p = nextprime(p)
print(ans)