N = int(input())
data = list(map(int, input().split()))
M = int(input())

low = 1
high = max(data)
max_sum = 0
while low <= high:
    mid = (low + high) // 2
    sum = 0
    for da in data:
        if da < mid:
            sum += da
        else:
            sum += mid
    if sum > max_sum and sum <= M:
        max_sum = sum
        ans = mid
    if sum < M:
        low = mid + 1
    elif sum > M:
        high = mid - 1
    else:
        ans = mid
        break
print(ans)