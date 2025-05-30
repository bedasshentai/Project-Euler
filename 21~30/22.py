form = [xxx.txt] // TOOOOO LONG
form = sorted(form)
ans = 0
i = 1
for s in form:
    sum = 0
    for c in s:
        sum += ord(c) - ord('A') + 1
    sum *= i
    i += 1
    ans += sum
print(ans)