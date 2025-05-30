ans = 0
for i in range(1000000):
    x = i
    sum = 0
    while x > 0:
        sum += pow(x % 10, 5)
        x //= 10
    if sum == i:
        ans += i
print(ans - 1)