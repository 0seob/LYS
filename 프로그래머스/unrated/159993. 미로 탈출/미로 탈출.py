from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def solution(maps):
    answer = 0
    len_row, len_col = len(maps), len(maps[0])
    sx, sy, ex, ey, lx, ly = -1, -1, -1, -1, -1, -1
    dq = deque()
    new_maps = []
    visit = [[[0 for _ in range(2)] for _ in range(len(maps[0]))] for _ in range(len(maps))]
    for i, row in enumerate(maps):
        for j, col in enumerate(row):
            if maps[i][j] == 'S':
                sx, sy = i, j
                break
    dq.append((sx, sy, 0, 0))
    visit[sx][sy][0] = 1
    while dq:
        cx, cy, lever, cnt = dq.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or nx >= len_row or ny < 0 or ny >= len_col:
                continue
            if maps[nx][ny] == 'X' or visit[nx][ny][lever] == 1:
                continue
            if maps[nx][ny] == 'L':
                dq.append((nx, ny, 1, cnt+1))
                visit[nx][ny][1] = 1
                continue
            if maps[nx][ny] == 'E' and lever == 1:
                return cnt+1
            dq.append((nx, ny, lever, cnt+1))
            visit[nx][ny][lever] = 1
    return -1

'''
SOOOO
XXXXO
OOOOO
XXOXX
LOOOE
'''