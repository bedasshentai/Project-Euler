from sympy import *

for i in range(1001, 10000, 2):
    for j in range(2, (10000 - i) // 2, 2):
        if isprime(i) and isprime(i + j) and isprime(i + j * 2):
            if set(str(i)) == set(str(i + j)) == set(str(i + j * 2)):
                print(i, i + j, i + j * 2)