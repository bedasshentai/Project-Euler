dic = {''.join(sorted(str(pow(i, 3)))) : 0 for i in range(10000)}
for i in range(10000):
    dic[''.join(sorted(str(pow(i, 3))))] += 1

for i in range(10000):
    if dic[''.join(sorted(str(pow(i, 3))))] == 5:
        print(pow(i, 3))
        break
