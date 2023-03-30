from collections import deque

N = int(input())
K = int(input())

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

dq = deque()
snake = deque()
board = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(K):
    x, y = input().split()
    board[int(x)-1][int(y)-1] = 1
# for i in range(len(board)):
#     print(board[i])
L = int(input())
for _ in range(L):
    num, cdir = input().split()
    dq.append((int(num), cdir))
cnt = 0
dir = 2
snake.append((0, 0))
nx, ny = 0, 0
while True:
    cnt += 1
    nx += dx[dir]
    ny += dy[dir]
    
    if nx < 0 or nx >= N or ny < 0 or ny >= N: break
    if (nx, ny) in snake:
        break
    elif board[nx][ny] == 1:
        snake.append((nx, ny))
        board[nx][ny] = 0
    elif board[nx][ny] == 0:
        snake.append((nx, ny))
        snake.popleft()

    # if board[nx][ny] == 1:
    #     if (nx, ny) not in snake:
    #         snake.append((nx, ny))
    #     else: break
    # elif board[nx][ny] == 0:
    #     if (nx, ny) in snake:
    #         break
    #     else:
    #         snake.popleft()
    #         snake.append((nx, ny))
    # cnt += 1
    # print(cnt, nx, ny, len(snake))
    # print(snake)
    if dq and cnt == dq[0][0]:
        dis, cdir = dq.popleft()
        if cdir == 'L':
            dir = (dir + 3) % 4
        else:
            dir = (dir + 1) % 4
    # nx += dx[dir]
    # ny += dy[dir]
    # if nx < 0 or ny >= N or nx >= N or ny < 0: break
    # if board[nx][ny] != 1:
    #     snake.popleft()
    # else:
    #     board[nx][ny] = 0
    
    
print(cnt)