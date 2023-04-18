n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

for i in range(1, n):
    data[i][0] += data[i-1][0]
    for j in range(1, i):
        data[i][j] += max(data[i-1][j-1], data[i-1][j])
    data[i][i] += data[i-1][i-1]
print(max(data[-1]))