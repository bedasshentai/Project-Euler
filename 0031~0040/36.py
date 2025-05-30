from sympy import *

ans = 0
for i in range(1, 1000000, 2):
    if str(i)[::-1] == str(i) and str(bin(i))[2:][::-1] == str(bin(i))[2:]:
        ans += i
print(ans)
