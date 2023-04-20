R, C = map(int, input().split())
board = [input() for _ in range(R)]
visit = [[0]*C for _ in range(R)]
ans = 1

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

dq = set()
dq.add((0, 0, board[0][0]))
visit[0][0] = 1

while dq:
    cx, cy, alp = dq.pop()
    for dir in range(4):
        nx = cx + dx[dir]
        ny = cy + dy[dir]
        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            continue
        if board[nx][ny] in alp:
            continue
        dq.add((nx, ny, alp+board[nx][ny]))
        ans = max(ans, len(alp)+1)
        
print(ans)
