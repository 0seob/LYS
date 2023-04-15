def solution(s):
    answer = 0
    is_x, not_x = 0, 0
    while len(s) > 1:
        x = s[0]
        s = s[1:]
        is_x, not_x = 1, 0
        for idx, i in enumerate(s):
            if i == x:
                is_x += 1
            else:
                not_x += 1
            if is_x == not_x:
                s = s[idx+1:]
                answer += 1
                is_x, not_x = 0, 0
                break
        else:
            s = ''
    if len(s) == 1 or is_x > 0 or not_x > 0:
        answer += 1
    return answer