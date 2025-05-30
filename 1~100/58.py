from sympy import *
from itertools import *
from fractions import *

def f1(x): return 4 * x ** 2 - 10 * x + 7
def f2(x): return 4 * x ** 2 - 8 * x + 5
def f3(x): return 4 * x ** 2 - 6 * x + 3

total = 1
cnt = 0
i = 1
while(1):
    i += 1
    total += 4
    cnt += isprime(f1(i))
    cnt += isprime(f2(i))
    cnt += isprime(f3(i))
    if cnt / total < 0.1: break
print(i * 2 - 1)