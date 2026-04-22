from collections import Counter

def find_max_palin_len(word: str) -> int:
    counter = Counter(word)
    found_odd = False
    n = 0
    for _, i in counter.most_common():
        n += i
        if i % 2 != 0:
            if found_odd:
                n -= 1
            found_odd = True
    return n

print(find_max_palin_len(input()))
