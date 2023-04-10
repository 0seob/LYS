def solution(sequence, k):
    answer = []
    arr = [0]
    for i in range(len(sequence)):
        arr.append(arr[i]+sequence[i])
    min_len = 1000000001
    point = [1000001, 1000001]
    end = len(arr)-1
    start = len(arr)-2
    while True:
        if arr[end] - arr[start] > k:
            end -= 1
        # print(start, end, arr[start], arr[end])
        elif arr[end] - arr[start] == k:
            if min_len > end - start:
                point = [start, end]
                min_len = end - start
            elif min_len == end - start:
                if point[1] > start:
                    point = [start, end]
                    min_len = end - start
            if start > 0:
                start -= 1
            if end > 0:
                end -= 1
        else:
            if start > 0:
                start -= 1
            elif start == 0:
                break
    answer = [point[0], point[1]-1]
    return answer