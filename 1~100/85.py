ans = 0
S = 0
target = 2e6
for i in range(1, 1400):
    for j in range(1, 1400):
        cnt = i * (i + 1) * j * (j + 1) // 4
        if abs(ans - target) > abs(cnt - target):
            ans = cnt
            S = i * j
print(S)
