from sympy import *

is_sqr = [0 for _ in range(1000)]
for i in range(40):
    is_sqr[i * (i + 1) // 2] = 1
words = ["word.txt"]
ans = 0
for word in words:
    cnt = 0
    for s in word:
        cnt += ord(s) - ord('A') + 1
    ans += is_sqr[cnt]
print(ans)
