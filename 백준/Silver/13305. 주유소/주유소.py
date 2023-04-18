N = int(input())
road = list(map(int, input().split()))
dpl = list(map(int, input().split()))
for i in range(1, len(dpl)):
    dpl[i] = min(dpl[i-1], dpl[i])
ans = 0
for idx, r in enumerate(road):
    ans += dpl[idx] * r
print(ans)