from sympy import *
num = []
for i in range(10):
    num.append(i)
A = 1e6 - 1
ls = []
for i in range(10):
    cnt = A // factorial(9 - i)
    A = A % factorial(9 - i)
    ls.append(num[cnt])
    num.remove(num[cnt])
for i in ls:
    print(i, end='')