from gmpy2 import *
c = 1
cnt = 0
while cnt < 1e6:
    c += 1
    for sum in range(2, 2 * c):
        path = gmpy2.iroot(sum * sum + c * c, 2)
        if path[1] == True:
            if sum > c:
                cnt += c - (sum + 1) // 2 + 1
            else:
                cnt += sum // 2
print(c)