from numpy import *

A = matrix([[1, -2, 2],
            [2, -1, 2],
            [2, -2, 3]])
B = matrix([[1, 2, 2],
            [2, 1, 2],
            [2, 2, 3]])
C = matrix([[-1, 2, 2],
            [-2, 1, 2],
            [-2, 2, 3]])
O = matrix([[3], [4], [5]])

triangles = [O]
maxn = 1500000
L = []

for ori in triangles:
    L.append(sum(ori))
    nxtA, nxtB, nxtC = A * ori, B * ori, C * ori
    if sum(nxtA) <= maxn: triangles.append(nxtA)
    if sum(nxtB) <= maxn: triangles.append(nxtB)
    if sum(nxtC) <= maxn: triangles.append(nxtC)

cnt = [0 for _ in range(maxn + 1)]
for ay in L:
    for i in range(ay, maxn + 1, ay):
        cnt[i] += 1

ans = 0
for i in range(maxn + 1):
    if cnt[i] == 1:
        ans += 1

print(ans)