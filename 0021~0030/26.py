from sympy import *
ans = 1
num = 1
for i in range(2, 1000):
    j = 1
    t = i
    while t % 2 == 0: t //= 2
    while t % 5 == 0: t //= 5
    while pow(10, j, t) != 1: j += 1
    if ans < j and pow(10, j, t) == 1:
        ans = j
        num = i
print(num)