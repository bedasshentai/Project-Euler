n = 12000
ans = 0

a, b = 1, 3
c, d = 1, 2
k = min((n - c) // a, (n - d) // b)
c, d = c + k * a, d + k * b

while c * 2 < d:
    k = (n + b) // d
    a, b, c, d = c, d, k * c - a, k * d - b
    ans += 1

print(ans)