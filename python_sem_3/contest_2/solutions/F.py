import re
import sys
from collections import Counter

n = int(sys.stdin.readline())
s = sys.stdin.read()

words = Counter()
for word in re.finditer(r"[A-Za-z]+", s):
    words[word.group().lower()] += 1
print(*sorted(words.keys(), key=lambda w: (-words[w], w))[:n])
