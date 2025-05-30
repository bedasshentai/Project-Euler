from numpy import *
A = matrix([[1, -2, 2],
            [2, -1, 2],
            [2, -2, 3]])
C = matrix([[-1, 2, 2],
            [-2, 1, 2],
            [-2, 2, 3]])
pythagorean = matrix([[3], [4], [5]])
limit = 1e9
switch = 0
ans = 0

while sum(pythagorean) <= limit:
    ans += max(pythagorean) * 2 + min(pythagorean) * 2
    if switch:
        pythagorean = A * pythagorean
        switch = 0
    else:
        pythagorean = C * pythagorean
        switch = 1

print(ans)
