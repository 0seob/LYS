N = int(input())
dp = [0 for _ in range(30)]
dp[1] = 3
for i in range(3, N, 2):
    dp[i] = dp[i-2] * 3 + 2
    for j in range(3, i, 2):
        dp[i] += dp[i-j-1] * 2
print(dp[N-1])
