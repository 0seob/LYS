N, M = map(int, input().split())
memory = [0] + list(map(int, input().split()))
cash = [0] + list(map(int, input().split()))
ans = sum(cash)
data = [[0]*(sum(cash)+1) for _ in range(N+1)]
for i in range(1, N+1):
    mem = memory[i]
    cas = cash[i]
    for j in range(1, sum(cash)+1):
        if j < cas:
            data[i][j] = data[i-1][j]
        else:
            data[i][j] = max(mem + data[i-1][j-cas], data[i-1][j])
        if data[i][j] >= M:
            ans = min(ans, j)
if M != 0:
    print(ans)
else:
    print(0)