import sys
input = sys.stdin.readline

cost = []

N = int(input())

for i in range(N):
    ls = list(map(int, input().split()))
    cost.append(ls)

pay = []
tmp = []
for i in range(3):
    tmp.append(cost[0][i])
pay.append(tmp)

for i, ls in enumerate(cost[1:]):
    temp = []
    temp.append(min(pay[i][1], pay[i][2]) + ls[0])
    temp.append(min(pay[i][0], pay[i][2]) + ls[1])
    temp.append(min(pay[i][0], pay[i][1]) + ls[2])
    pay.append(temp)

print(min(pay[N-1]))