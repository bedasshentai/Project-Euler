from sympy import *

ans = 0
for i in range(9999, 9000, -1):
    res = str(i) + str(i << 1)
    if set(res) == set("123456789"):
        ans = max(ans, int(res))
print(ans)
