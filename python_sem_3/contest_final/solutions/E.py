def solution(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(n, i - 1, -1):
            dp[j] += dp[j - i]
            dp[j] %= 1_000_000_007
    return dp[n] % 1_000_000_007

if __name__ == '__main__':
    print(solution(int(input())))
