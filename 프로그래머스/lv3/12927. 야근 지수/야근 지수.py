import heapq

def solution(n, works):
    answer = 0
    heap = []
    for i in works:
        heapq.heappush(heap, -i)
    for _ in range(n):
        if len(heap) <= 0:
            break
        out = heapq.heappop(heap)
        if out < 0:
            heapq.heappush(heap, out+1)
    for hp in heap:
        answer += hp ** 2
    return answer