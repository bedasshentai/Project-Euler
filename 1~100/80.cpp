from decimal import *

getcontext().prec = 105
ans = 0
for i in range(2, 101):
    if i ** 0.5 == int(i ** 0.5): continue
    sqr = str(Decimal(i) ** Decimal(0.5))
    sqr = sqr.replace('.', '')
    ans += sum(int(j) for j in sqr[:100])

print(ans)