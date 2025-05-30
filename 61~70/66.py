from fractions import *
from numpy import *

def solve(D):
    b = 0
    c = 1
    sq = int(sqrt(D))
    if sq * sq == D:
        return []
    lis = [int((sq + b) / c)]
    while lis[-1] != lis[0] * 2:
        b = lis[-1] * c - b
        c = (D - b * b) // c
        lis.append(int((sq + b) / c))
    return lis

def pell_min(D):
    lis = solve(D)
    if len(lis) == 0:
        return 0, 0
    x, y = 0, 1
    lis.pop(-1)
    r = len(lis)
    while len(lis) > 0:
        x, y = y, x + lis[-1] * y
        lis.pop(-1)
    if r & 1:
        return 2 * x * x - 1, 2 * x * y
    else:
        return x, y

ans = 0
maxD = 0
for D in range(1, 1001):
    x, y = pell_min(D)
    if ans < x:
        ans = x
        maxD = D

print(maxD, ans)