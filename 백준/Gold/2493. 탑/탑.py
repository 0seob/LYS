N = int(input())
top = list(map(int, input().split()))
ans = [0] * N
temp = []
for idx, tp in enumerate(top):
    if idx == 0:
        temp.append((idx, tp))
    if temp[-1][1] <= tp:
        while temp and temp[-1][1] <= tp:
            temp.pop()
        if len(temp):
            ans[idx] = temp[-1][0] + 1
        temp.append((idx, tp))
    else:
        ans[idx] = temp[-1][0] + 1
        temp.append((idx, tp))
for an in ans:
    print(an, end=" ")
