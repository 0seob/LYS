from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def find_block():
    # 크기가 큰 블록 그룹
    # 무지개 블록 수가 가장 많은 그룹
    # 행이 가장 큰 것
    # 열이 가장 큰 것
    temp = []
    visit = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            cnt, rb = 0, 0
            if board[i][j] > 0 and visit[i][j] == 0:
                dq = deque()
                dq.append((i, j))
                val = board[i][j]
                while dq:
                    cx, cy = dq.popleft()
                    for k in range(4):
                        nx = cx + dx[k]
                        ny = cy + dy[k]
                        if nx < 0 or ny < 0 or nx >= N or ny >= N:
                            continue
                        if board[nx][ny] == -1 or visit[nx][ny] != 0:
                            continue
                        if board[nx][ny] == val:
                            cnt += 1
                            visit[nx][ny] = 1
                            dq.append((nx, ny))
                        elif board[nx][ny] == 0:
                            cnt += 1
                            rb += 1
                            visit[nx][ny] = -1
                            dq.append((nx, ny))

            for m in range(N):
                for n in range(N):
                    if visit[m][n] == -1:
                        visit[m][n] = 0
            temp.append((cnt, rb, i, j))
    if temp:
        temp.sort(key=lambda x: (-x[0], -x[1], -x[2], -x[3]))
    else:
        return 0
    point = temp[0][0]**2
    dq = deque()
    visit = [[0] * N for _ in range(N)]
    dq.append((temp[0][2], temp[0][3]))
    val = board[temp[0][2]][temp[0][3]]
    board[temp[0][2]][temp[0][3]] = -2
    while dq:
        cx, cy = dq.popleft()
        for k in range(4):
            nx = cx + dx[k]
            ny = cy + dy[k]
            if nx < 0 or ny < 0 or nx >= N or ny >= N:
                continue
            if board[nx][ny] == -1 or visit[nx][ny] > 0:
                continue
            if board[nx][ny] == val or board[nx][ny] == 0:
                board[nx][ny] = -2
                dq.append((nx, ny))
                visit[nx][ny] = 1
    return point


def gravity():
    for j in range(N):
        temp = []
        for i in range(N):
            if board[i][j] >= 0:
                temp.append(board[i][j])
                board[i][j] = -2
            elif board[i][j] == -1:
                for tp in range(len(temp)):
                    board[i-tp-1][j] = temp.pop()
        if temp:
            for i in range(len(temp)):
                board[N-1-i][j] = temp.pop()


def rotate_90():
    global board
    temp = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            temp[N-1-j][i] = board[i][j]
    board = [temp[i][:] for i in range(N)]


N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
# for i in range(N):
#     print(board[i])
# print()
# print(find_block())
# for i in range(N):
#     print(board[i])
# print()
# gravity()
# for i in range(N):
#     print(board[i])
# print()
# rotate_90()
# for i in range(N):
#     print(board[i])
# print()
# gravity()
# for i in range(N):
#     print(board[i])
# print()
sum_point = 0
while True:
    block = find_block()
    if block:
        sum_point += block
    else:
        break
    gravity()
    rotate_90()
    gravity()
print(sum_point)