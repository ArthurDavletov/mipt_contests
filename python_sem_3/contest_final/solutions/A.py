def solution(k: int, s: map) -> list:
    result = []
    state = 0
    temp = 0
    for i in s:
        if i == 2:
            result.append(temp)
            break
        if state == i:
            if temp >= k:
                result.extend((temp, 0))
                temp = 1
            else:
                temp += 1
        else:
            state = (0, 1)[i]
            result.append(temp)
            temp = 1
    return result


if __name__ == '__main__':
    k = int(input())
    numbers = map(int, input().split())
    print(*solution(k, numbers))
