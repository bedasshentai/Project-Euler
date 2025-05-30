cnt = 1
a = "1"
b = "1"
while len(a) < 1000:
    c = int(a) + int(b)
    a = b
    b = str(c)
    cnt += 1
print(cnt)