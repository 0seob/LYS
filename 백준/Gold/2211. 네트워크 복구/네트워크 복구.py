from collections import defaultdict
import heapq, sys
input = sys.stdin.readline
INF = sys.maxsize

n, m = map(int, input().split())
graph = defaultdict(list)
distance = [float('inf')]*(n+1)
parent = [0]*(n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

pq = [(0, 1)]
distance[1] = 0
while pq:
    cur_dist, cx = heapq.heappop(pq)
    if distance[cx] < cur_dist:
        continue
    for nx, nxt_dist in graph[cx]:
        new_dist = nxt_dist + cur_dist
        if new_dist < distance[nx]:
            distance[nx] = new_dist
            heapq.heappush(pq, (new_dist, nx))
            parent[nx] = cx

print(n-1)
for i in range(2, n+1):
    print(i, parent[i])
