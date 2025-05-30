for i in range(900, 1000):
    for j in range(900, 1000):
        res = i * j
        if str(res) == str(res)[::-1]:
            print(res)