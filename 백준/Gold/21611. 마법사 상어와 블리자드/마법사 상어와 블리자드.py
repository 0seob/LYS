from collections import deque

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
dxi = [-1, 1, 0, 0]
dyi = [0, 0, -1, 1]


def move_marble():
    nx, ny = N // 2, N // 2
    temp = deque()
    for i in range(1, N):
        for j in range(2):
            for k in range(i):
                if i % 2 == 1 and j % 2 == 0:
                    nx += dx[0]
                    ny += dy[0]
                elif i % 2 == 1 and j % 2 == 1:
                    nx += dx[1]
                    ny += dy[1]
                elif i % 2 == 0 and j % 2 == 0:
                    nx += dx[2]
                    ny += dy[2]
                elif i % 2 == 0 and j % 2 == 1:
                    nx += dx[3]
                    ny += dy[3]
                if board[nx][ny] != 0:
                    temp.append(board[nx][ny])
    for i in range(N-2, -1, -1):
        if board[0][i] != 0:
            temp.append(board[0][i])
    nx, ny = N // 2, N // 2
    flag = False
    new_board = [[0]*N for _ in range(N)]
    new_board[nx][ny] = -1
    for i in range(1, N):
        if flag == True:
            break
        for j in range(2):
            if flag == True:
                break
            for k in range(i):
                if i % 2 == 1 and j % 2 == 0:
                    nx += dx[0]
                    ny += dy[0]
                elif i % 2 == 1 and j % 2 == 1:
                    nx += dx[1]
                    ny += dy[1]
                elif i % 2 == 0 and j % 2 == 0:
                    nx += dx[2]
                    ny += dy[2]
                elif i % 2 == 0 and j % 2 == 1:
                    nx += dx[3]
                    ny += dy[3]
                if len(temp):
                    new_board[nx][ny] = temp.popleft()
                else:
                    flag = True
                    break
    if flag == False:
        for i in range(N-2, -1, -1):
            if len(temp):
                new_board[0][i] = temp.popleft()
            else:
                break
    return new_board


def ice_break(di, si):  # di 방향으로 거리가 si 이하인 구슬을 폭발
    global board
    x, y = N//2, N//2
    for i in range(si):
        x += dxi[di-1]
        y += dyi[di-1]
        board[x][y] = 0


def explosion():  # 구슬이 4개 이상 연속 하였을 때, 폭발
    nx, ny = N // 2, N // 2
    temp = []
    cnt = 0
    for i in range(1, N):
        for j in range(2):
            for k in range(i):
                val = board[nx][ny]
                if i % 2 == 1 and j % 2 == 0:
                    nx += dx[0]
                    ny += dy[0]
                elif i % 2 == 1 and j % 2 == 1:
                    nx += dx[1]
                    ny += dy[1]
                elif i % 2 == 0 and j % 2 == 0:
                    nx += dx[2]
                    ny += dy[2]
                elif i % 2 == 0 and j % 2 == 1:
                    nx += dx[3]
                    ny += dy[3]
                if val != board[nx][ny]:
                    if len(temp) >= 4:
                        cnt += len(temp) * val
                        for tx, ty in temp:
                            board[tx][ty] = 0
                    temp = []
                temp.append((nx, ny))
    for i in range(N-2, -1, -1):
        val = board[0][i+1]
        if val != board[0][i]:
            if len(temp) >= 4:
                cnt += len(temp) * val
                for tx, ty in temp:
                    board[tx][ty] = 0
            temp = []
        temp.append((0, i))
    if temp:
        for tx, ty in temp:
            board[tx][ty] = 0
    return cnt


def change_marble():
    nx, ny = N//2, N//2
    temp = deque()
    cnt = 1
    flag = False
    for i in range(1, N):
        if flag == True:
            break
        for j in range(2):
            if flag == True:
                break
            for k in range(i):
                val = board[nx][ny]
                if val == 0:
                    flag = True
                    break
                if i % 2 == 1 and j % 2 == 0:
                    nx += dx[0]
                    ny += dy[0]
                elif i % 2 == 1 and j % 2 == 1:
                    nx += dx[1]
                    ny += dy[1]
                elif i % 2 == 0 and j % 2 == 0:
                    nx += dx[2]
                    ny += dy[2]
                elif i % 2 == 0 and j % 2 == 1:
                    nx += dx[3]
                    ny += dy[3]
                if val != board[nx][ny]:
                    temp.append(cnt)
                    temp.append(val)
                    cnt = 1
                else:
                    cnt += 1
    if flag == False:
        nx, ny = 0, N-1
        for i in range(N-1, 0, -1):
            val = board[nx][ny]
            if val == 0:
                flag = True
                break
            nx += dx[0]
            ny += dy[0]
            if val != board[nx][ny]:
                temp.append(cnt)
                temp.append(val)
                cnt = 1
            else:
                cnt += 1
        if flag == False:
            temp.append(cnt)
            temp.append(val)
    temp.popleft()
    temp.popleft()
    new_board = [[0]*N for _ in range(N)]
    nx, ny = N // 2, N // 2
    new_board[nx][ny] = -1
    flag = False
    for i in range(1, N):
        if flag == True:
            break
        for j in range(2):
            if flag == True:
                break
            for k in range(i):
                if i % 2 == 1 and j % 2 == 0:
                    nx += dx[0]
                    ny += dy[0]
                elif i % 2 == 1 and j % 2 == 1:
                    nx += dx[1]
                    ny += dy[1]
                elif i % 2 == 0 and j % 2 == 0:
                    nx += dx[2]
                    ny += dy[2]
                elif i % 2 == 0 and j % 2 == 1:
                    nx += dx[3]
                    ny += dy[3]
                if len(temp) > 0:
                    new_board[nx][ny] = temp.popleft()
                else:
                    flag = True
                    break
    if flag == False:
        for i in range(N-2, -1, -1):
            if len(temp) > 0:
                new_board[0][i] = temp.popleft()
            else:
                break
    return new_board




N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
board[N//2][N//2] = -1
magic = [list(map(int, input().split())) for _ in range(M)]
point = 0
for mg in magic:
    ice_break(mg[0], mg[1])
    board = move_marble()
    while True:
        boom = explosion()
        if boom:
            board = move_marble()
            point += boom
        else:
            break
    board = change_marble()
print(point)
# for i in range(N):
#     print(board[i])
# print()
# ice_break(magic[0][0], magic[0][1])
# for i in range(N):
#     print(board[i])
# print()
# board = move_marble()
# for i in range(N):
#     print(board[i])
# print()
# boom = explosion()
# for i in range(N):
#     print(board[i])
# print()
# board = move_marble()
# for i in range(N):
#     print(board[i])
# print()
# boom = explosion()
# if boom:
#     board = move_marble()
# for i in range(N):
#     print(board[i])
# print()
# board = change_marble()
# for i in range(N):
#     print(board[i])
# print()
