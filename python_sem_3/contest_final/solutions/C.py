def is_win(n: int, k: int) -> bool:
    return n % (k + 1) != 0


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        if is_win(*map(int, input().split())):
            print("Pasha")
        else:
            print("Artur")
