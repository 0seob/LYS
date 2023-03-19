import sys
input = sys.stdin.readline

from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def move(x, y, dx, dy):
    cnt = 0
    while arr[x+dx][y+dy] != '#' and arr[x][y] != 'O':
        x += dx
        y += dy
        cnt += 1
    return x, y, cnt

def bfs():
    while dq:
        rx, ry, bx, by, depth = dq.popleft()
        if depth >= 10:
            return 0
        for i in range(4):
            nrx, nry, rcnt = move(rx, ry, dx[i], dy[i])
            nbx, nby, bcnt = move(bx, by, dx[i], dy[i])
            if arr[nbx][nby] != 'O':
                if arr[nrx][nry] == 'O':
                    return 1
                if visit[nrx][nry][nbx][nby]:
                    continue
                if nrx == nbx and nry == nby:
                    if rcnt > bcnt:
                        nrx -= dx[i]
                        nry -= dy[i]
                    else:
                        nbx -= dx[i]
                        nby -= dy[i]
                visit[nrx][nry][nbx][nby] = 1
                dq.append((nrx, nry, nbx, nby, depth+1))
    return 0

N, M = map(int, input().split())
arr = [list(map(str, input().rstrip())) for _ in range(N)]
visit = [[[[0 for _ in range(M)] for _ in range(N)] for _ in range(M)] for _ in range(N)]
dq = deque()

for i in range(N):
    for j in range(M):
        if arr[i][j] == 'R':
            rx, ry = i, j
        elif arr[i][j] == 'B':
            bx, by = i, j

dq.append((rx, ry, bx, by, 0))
visit[rx][ry][bx][by] = 1
print(bfs())
