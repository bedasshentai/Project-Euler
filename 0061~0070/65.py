from fractions import *

e = [2, 1]
for i in range(98):
    if i % 3 == 0: e.append((i // 3 + 1) * 2)
    else: e.append(1)
e = e[::-1]

ans = Fraction(e[0])
e.pop(0)
for i in e:
    ans = 1 / ans + i
print(sum(map(int, str(ans.numerator))))