N = int(input())
road = list(map(int, input().split()))
dpl = list(map(int, input().split()))
new_dpl = []
for idx, dp in enumerate(dpl):
    new_dpl.append((idx, dp))
new_dpl.sort(key= lambda x: x[1])
ans = 0
for idx, r in enumerate(road):
    for nd in new_dpl:
        if nd[0] <= idx:
            ans += nd[1] * r
            break
print(ans)