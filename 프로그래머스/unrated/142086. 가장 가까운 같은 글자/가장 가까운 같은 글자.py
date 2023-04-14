def solution(s):
    answer = []
    new_dict = {}
    for idx, i in enumerate(s):
        if i not in new_dict:
            new_dict[i] = (-1, idx)
            answer.append(-1)
        else:
            answer.append(idx-new_dict[i][1])
            new_dict[i] = (new_dict[i][1], idx)
    return answer