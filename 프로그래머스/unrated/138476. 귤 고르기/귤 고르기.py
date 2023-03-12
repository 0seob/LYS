def solution(k, tangerine):
    answer = 0
    num = 0
    data = {}
    for tan in tangerine:
        if tan not in data:
            data[tan] = 1
        else:
            data[tan] += 1
    tan_list = list(sorted(data.items(), reverse = True, key = lambda x:x[1]))
    for i in tan_list:
        num += int(i[1])
        answer += 1
        if num >= k:
            return answer
    return answer