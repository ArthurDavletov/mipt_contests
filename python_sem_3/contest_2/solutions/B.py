def to_roman(n: int) -> str:
    if n == 0:
        return ""
    table = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M",
             4: "IV", 9: "IX", 40: "XL", 90: "XC", 400: "CD", 900: "CM"}
    if n in table:
        return table[n]
    answer = ""
    for base in sorted(table, reverse = True):
        if n > base:
            return ((n // base) * table[base]) + to_roman(n % base)

print(to_roman(int(input())))
