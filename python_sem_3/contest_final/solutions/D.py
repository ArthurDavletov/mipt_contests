from operator import itemgetter

if __name__ == '__main__':
    n = int(input())
    users = list(enumerate(map(int, input().split())))
    taxis = list(enumerate(map(int, input().split()), start=1))
    users.sort(key=itemgetter(1))
    taxis.sort(key=itemgetter(1), reverse = True)
    result = [0] * n
    for user, taxi in zip(users, taxis):
        result[user[0]] = taxi[0]
    print(*result)
