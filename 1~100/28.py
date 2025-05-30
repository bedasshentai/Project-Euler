from sympy import *
ans = 0
for n in range(1, 501, 1):
    ans += 4 * n * n + 3 * n + 1
    ans += 4 * n * n - 9 * n + 6
print(ans * 2 + 1)
