ans = 0
a = 0
b = 1
for i in range(10000000):
    c = a + b
    a = b
    b = c
    if c > 4000000:
        break
    if c & 1:
        continue
    ans += c
print(ans)