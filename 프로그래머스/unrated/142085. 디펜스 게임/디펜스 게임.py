from heapq import heappush, heappop, heapify

def solution(n, k, enemy):
    answer = 0
    new_list = []
    heap = []
    if len(enemy) < k:
        return len(enemy)
    for i in range(k):
        heappush(heap, enemy[i])
    for i in range(k, len(enemy)):
        heappush(heap, enemy[i])
        n -= heappop(heap)
        if n < 0:
            return i
    return len(enemy)