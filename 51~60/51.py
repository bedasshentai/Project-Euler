from sympy import *
from itertools import *

number = ''
for i in range(10): number += str(i) * 3
for i in list(set(combinations(number, 3))):
    for check in permutations(''.join(map(str, i)) + 'd' * 3):
        check = ''.join(map(str, check))
        if check[0] == '0': continue
        cnt = 0
        minn = 1e7
        for d in range(10):
            res = check.replace('d', str(d))
            if res[0] != '0' and isprime(int(res)):
                cnt += 1
                minn = min(minn, int(res))
        if cnt == 8:
            print(minn)