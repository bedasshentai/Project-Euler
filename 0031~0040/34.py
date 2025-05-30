from sympy import *

def calc(t):
    x = t
    res = 0
    while x > 0:
        res += factorial(x % 10)
        x //= 10
    return res == t

ans = 0
for i in range(10, 7 * factorial(9) + 1):
    if (calc(i)):
        ans += i
print(ans)