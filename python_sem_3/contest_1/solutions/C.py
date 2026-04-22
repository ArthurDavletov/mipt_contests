def number_generator(n: int):
    delta = -1
    while True:
        yield n + delta
        delta = -delta if delta < 0 else ~delta


def is_leap(year: int) -> bool:
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return year % 4 == 0


def find_closest_leap(year: int) -> int:
    for i in number_generator(year):
        if is_leap(i):
            return i


year = int(input())

if is_leap(year):
    print(True)
else:
    print(False, find_closest_leap(year))
