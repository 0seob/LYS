def solution(n, s):
    answer = []
    sum_val = 1
    if n > s:
        return [-1]
    else:
        div = s // n
        answer = [div for _ in range(n)]
        rem = s % n
        for i in range(rem):
            answer[i] += 1
    answer.sort()
        
    return answer