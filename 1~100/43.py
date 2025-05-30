from sympy import *
from itertools import *

S = "0123456789"
lis = permutations(S)
primes = [2, 3, 5, 7, 11, 13, 17]
ans = 0
for num in lis:
    flag = 0
    num = "".join(num)
    for i in range(7):
        if int(num[i + 1 : i + 4]) % primes[i] > 0:
            flag = 1
    if not flag: ans += int(num)
print(ans)
