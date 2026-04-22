numbers = sorted(set(map(int, input().split())))
left = right = numbers[0]
for i in range(1, len(numbers)):
    if numbers[i] - right == 1:
        right += 1
    else:
        if left == right:
            print(left)
        else:
            print(f"{left}->{right}")
        left = right = numbers[i]


# ÑÐ´Ð¸Ð²Ð»ÑÑÑ, ÐµÑÐ»Ð¸ ÑÑÐ¾ Ð¿ÑÐ¾Ð¹Ð´ÑÑ
if left == right:
    print(left)
else:
    print(f"{left}->{right}")
