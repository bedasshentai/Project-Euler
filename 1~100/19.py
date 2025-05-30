days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
year = 1900
month = 0
day = 0
weekday = 1
ans = 0
while year < 2001:
    if year > 1900 and weekday == 0 and day == 0:
        ans += 1
    weekday = (weekday + 1) % 7
    day += 1
    delta = 0
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        delta = 1
    if day == days[month] or month == 1 and day == days[month] + delta:
        day = 0
        month += 1
    if month == 12:
        month = 0
        year += 1
print(ans)