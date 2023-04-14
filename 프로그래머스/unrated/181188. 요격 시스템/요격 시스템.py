def solution(targets):
    answer = 1
    targets.sort()
    start, end = targets[0][0], targets[0][1]
    for i in range(1, len(targets)):
        if targets[i][0] >= end:
            answer += 1
            start, end = targets[i][0], targets[i][1]
        elif targets[i][1] < end:
            end = targets[i][1]
            
    return answer