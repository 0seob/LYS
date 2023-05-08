import sys
input = sys.stdin.readline

N, M = map(int, input().split())
keyword = {}
for _ in range(N):
    keyword[input().rstrip()] = 1
writing = set()
for _ in range(M):
    tp = input().rstrip().split(',')
    for i in tp:
        if i in keyword:
            keyword.pop(i)
    print(len(keyword))