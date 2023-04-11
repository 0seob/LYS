def solution(scores):
    answer = 1
    wanho = scores[0]
    wanho_sum = sum(wanho)
    scores.sort(key= lambda x: [-x[0], x[1]])
    max_df = 0
    for s in scores:
        if wanho[0] < s[0] and wanho[1] < s[1]:
            return -1
        if max_df <= s[1]:
            if wanho_sum < s[0] + s[1]:
                answer += 1
            max_df = s[1]
    return answer