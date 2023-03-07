from itertools import combinations_with_replacement
def solution(n, info):
    answer = [-1]
    lst = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    comb = list(combinations_with_replacement(lst, n))
    max_val = 0
    for i in range(-1, -12, -1):
        print(info[i], end=" ")
    for event in comb:
        lion = 0
        apeach = 0
        lion_arrow = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] # 10점 -> 0점
        for idx in event:
            lion_arrow[10 - idx] += 1
        for i in range(11):
            if lion_arrow[i] > info[i]:
                lion += 10 - i
            elif lion_arrow[i] == 0 and info[i] == 0:
                pass
            else:
                apeach += 10 - i
        if lion > apeach and lion - apeach > max_val:
            answer = lion_arrow
            max_val = lion - apeach
        elif lion > apeach and lion - apeach == max_val:
            for i in range(-1, -12, -1):
                if answer[i] > lion_arrow[i]:
                    break
                elif answer[i] == lion_arrow[i]:
                    continue
                else:
                    answer = lion_arrow
                    max_val = lion - apeach
        
    return answer