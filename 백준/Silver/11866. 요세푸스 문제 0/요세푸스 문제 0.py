from collections import deque

N, K = map(int, input().split())
member = deque([i for i in range(1, N+1)])
ans = []
cnt = 0
while member:
    cnt += 1
    if cnt == K:
        val = member.popleft()
        ans.append(val)
        cnt = 0
    else:
        member.rotate(-1)

print("<", end="")
for a in ans[:-1]:
    print(a, end=", ")
print(str(ans[-1])+">")