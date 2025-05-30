from sympy import *
ans = []
for a in range(2, 101):
    for b in range(2, 101):
        t = pow(a, b)
        if t not in ans:
            ans.append(t)
print(len(ans))
