

T = int(input())
for _ in range(T):
    K = int(input())
    data = list(map(int, input().split()))
    dp = [[0]*K for i in range(K)]
    sum = [0]
    for dt in data:
        sum.append(sum[-1] + dt)
    for d in range(1, K):
        for i in range(K-d):
            j = d + i
            dp[i][j] = float("inf")
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j+1] - sum[i])
    print(dp[0][K-1])
    