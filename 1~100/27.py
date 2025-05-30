from sympy import *
ans = 0
a = 0
b = 0
for i in range(-1000, 1001):
    for j in range(-1000, 1001):
        if i + 1 + j <= 0: continue
        for k in range(1, 100):
            if not isprime(k * k + i * k + j):
                if ans < k - 1:
                    ans = k - 1
                    a = i
                    b = j
                break
print(a * b)
