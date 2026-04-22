def is_correct(s: str) -> tuple[bool, int]:
    table = {"(": ")", "[": "]", "{": "}", "<": ">"}
    q = []
    for index, letter in enumerate(s):
        if letter in table.keys():
            q.append(letter)
        elif letter in table.values():
            if len(q) < 1:
                return False, index + 1
            symb = q.pop()
            if letter != table[symb]:
                return False, index + 1
    if len(q) > 0:
        return False, len(s)
    return True, 0


word = input()
flag, index = is_correct(word)
if flag:
    print(True)
else:
    print(False, index)
