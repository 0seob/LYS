def solution(n, m, section):
    idx = 0
    answer = 0
    for pt in section:
        if idx == 0:
            idx = pt
            answer += 1
            continue
        else:
            if pt > idx + m - 1:
                idx = pt
                answer += 1
            
    return answer