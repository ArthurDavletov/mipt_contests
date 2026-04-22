import sys

def find_closest_numbers(numbers: set[int]) -> tuple[int | None, int | None]:
    if len(numbers) < 2:
        return None, None
    s = sorted(numbers)
    a, b = s[0], s[1]
    for i in range(2, len(s)):
        if s[i] - s[i - 1] < b - a:
            a, b = s[i - 1], s[i]
    return a, b

points: dict[int, set[int]] = {}

for line in sys.stdin:
    x, y = map(int, line.split())
    if x not in points:
        points[x] = set()
    points[x].add(y)

answer = None

for x1 in points:
    for x2 in points:
        if x1 == x2 or len(points[x1] & points[x2]) < 2:
            continue
        y1, y2 = find_closest_numbers(points[x1] & points[x2])
        answer = abs(y2 - y1) * abs(x2 - x1) if answer is None else min(answer, abs(y2 - y1) * abs(x2 - x1))

print(answer if answer is not None else 0)
