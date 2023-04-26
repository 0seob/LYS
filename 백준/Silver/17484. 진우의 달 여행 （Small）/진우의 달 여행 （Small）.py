def dfs(i, j, k, ans):
    if i == N-1:
        answer_list[j] = min(answer_list[j], ans)
        return
    if j == 0:
        if k != 0:
            dfs(i+1, j, 0, ans+data[i+1][j])
        dfs(i+1, j+1, 1, ans+data[i+1][j+1])
    elif j == M-1:
        if k != 0:
            dfs(i+1, j, 0, ans+data[i+1][j])
        dfs(i+1, j-1, -1, ans+data[i+1][j-1])
    else:
        for tmp in range(-1, 2):
            if k != tmp:
                dfs(i+1, j+tmp, tmp, ans+data[i+1][j+tmp])


N, M = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(N)]
answer_list = [10e8]*M
for i in range(M):
    dfs(0, i, 2, data[0][i])

print(min(answer_list))
