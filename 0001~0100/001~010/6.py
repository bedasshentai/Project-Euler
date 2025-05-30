sum = 0
mul = 0
for i in range(1, 101):
    sum += i
    mul += i * i
print(sum * sum - mul)