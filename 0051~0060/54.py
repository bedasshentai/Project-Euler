from sympy import *
from itertools import *

cmp = [str(i) for i in range(1, 10)] + ['T'] + ['J'] + ['Q'] + ['K'] + ['A']
reflection = {}
for i in range(len(cmp)):
    reflection[cmp[i]] = i

def high(numbers):
    result = 0
    for i in range(len(numbers)):
        result += pow(14, i) * numbers[i]
    return result

def check_level(player):
    same = len(set([player[i][1] for i in range(5)])) == 1
    numbers = sorted([reflection[player[i][0]] for i in range(5)])
    isflush = len(set(numbers)) == 5 and numbers[4] - numbers[0] == 4
    if same and isflush: return [8, high(numbers)]
    if isflush: return [4, high(numbers)]
    if same: return [5, high(numbers)]
    cnt = [0 for _ in range(14)]
    for i in numbers:
        cnt[i] += 1
    if cnt.count(4): return [7, cnt.index(4)]
    if cnt.count(3):
        if cnt.count(1): return [3, cnt.index(3)]
        return [6, cnt.index(3)]
    if cnt.count(2) == 2: return [2, high([cnt.index(1)] + [x for (x, y) in enumerate(cnt) if y == 2])]
    if cnt.count(2) == 1: return [1, high([x for (x, y) in enumerate(cnt) if y == 1] + [cnt.index(2)])]
    return [0, high(numbers)]

ans = 0
with open('poker.txt', 'r') as f:
    for lines in f.readlines():
        lines = lines.split()
        player1 = [lines[i] for i in range(5)]
        player2 = [lines[i + 5] for i in range(5)]
        level1 = check_level(player1)
        level2 = check_level(player2)
        if level1[0] > level2[0]: ans += 1
        elif level1[0] == level2[0] and level1[1] > level2[1]: ans += 1
print(ans)